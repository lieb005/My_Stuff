/* Basic Stamp communication */

#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1		/* enables some compiler checks on GNU */
#endif

#ifndef DEBUG
# define DEBUG 1			/*comment out to turn off console output */
#endif

enum {
  MODEL_BS2,
  MODEL_BS2e,
  MODEL_BS2sx,
  MODEL_BS2p24,
  MODEL_BS2p40,
  MODEL_BS2pe24,
  MODEL_BS2pe40,
  MODEL_UNKNOWN
};

char * model_names[MODEL_UNKNOWN + 1] = {
  "Basic Stamp 2",
  "Basic Stamp 2e",
  "Basic Stamp 2sx",
  "Basic Stamp 2p24",
  "Basic Stamp 2p40",
  "Basic Stamp 2pe24",
  "Basic Stamp 2pe40",
  "UNKNOWN"
};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <ctype.h>
#include <getopt.h>

//#define TRUE           1
#define FALSE          0
#define STATE_CRITICAL -13

//#define OK             0
//#define ERROR          -1

#define DEFAULT_TIMEOUT 10

#define BUFFER_SIZE    1024

extern int errno;

//int show_usage=FALSE;

char *device="/dev/bstamp";
//int probe_number=1;
//int battery_ok=FALSE;
int timeout=DEFAULT_TIMEOUT;
//int invert_test=FALSE;
//int use_celsius=FALSE;

int model;
float firmware_version;

char sendbuf[BUFFER_SIZE];
char recvbuf[BUFFER_SIZE];
char *tmpbuf;
int fd;
struct termios oldtios;
struct termios newtios;

void BS2_comm_init(void);
void BS2_comm_halt(void);
void BS2_reset(void);
int BS2_id(void);
// void BS2_write(char * str);
void BS2_read(char * str, int count);
int BS2_sendfile(void);
int BS2_sendfile(int);
int BS2_sendfile(char * fname);
void *timeout_handler(int sig);
void console(void);
void *control_c_handler(int sig);
void error_handler(char recv);
char BS2_send_bytes(char snd);
void set_model(char detect);
void set_firmware(char fid);

void usage(void);
void version(void);
int program_stamp(void);

int verbose;
int stdin_flag;
int console_flag;
int ANSI_flag;
int eol_flag;
int reset_flag;
int program_flag;
char *infile;
char *prog_name;

int main(int argc, char **argv) {
	int c;
	int rval;
	prog_name=argv[0];
	verbose=0;
	infile=0;
	stdin_flag=0;
	console_flag=0;
	ANSI_flag=1;
	eol_flag=1;
	reset_flag=0;
	program_flag=0;
	
	while (1) {
		int this_option_optind = optind ? optind : 1;
		int option_index = 0;
		static struct option long_options[] = {
			{"help", 0, 0, 'h'},
			{"version", 0, 0, 'v'},
			{"verbose", 0, 0, 'V'},
			{"console", 0, 0, 'c'},
			{"ANSI", 0, 0, 'A'},
			{"eol", 0, 0, 'e'},
			{"reset", 0, 0, 'r'},
			{"program", 0, 0, 'p'},
			{"device", 1, 0, 'd'},
			{"stdin", 0, 0, 's'},
			{"file", 1, 0, 'f'},
			{0, 0, 0, 0}
			};

		c = getopt_long(argc, argv, "h?vVcAerpd:sf:", long_options, &option_index);
		if (c == -1) break;

		switch (c) {
		case 'h':
		case '?': usage(); break;
		case 'v': version(); break;
		case 'V': verbose++; break;
		case 'c': console_flag=1; break;
		case 'A': ANSI_flag=0; break;
		case 'e': eol_flag=0; break;
		case 'r': console_flag=reset_flag=1; break; // Why reset prior to console if not console?
		case 'p': program_flag=1; break;
		case 'd': device=strdup(optarg); break;
		case 's': program_flag=stdin_flag=1; break; // Why specify stdin if not going to program?
		case 'f': program_flag=1; infile=strdup(optarg); break; // Why specify an input file if not going to program?
		default: printf ("?? getopt returned character code 0%o ??\n", c);
		}
	}

	if (verbose>4) {
		printf("verbose: %d\n", verbose);
		printf("console: %d\n", console_flag);
		printf("ANSI: %d\n", ANSI_flag);
		printf("eol: %d\n", eol_flag);
		printf("reset: %d\n", reset_flag);
		printf("program: %d\n", program_flag);
		printf("device: %s\n",device);
		printf("stdin\n");
		printf("infile: %s\n",infile);
	}
	
	if (optind < argc) {
		if (verbose>4) printf ("non-option ARGV-elements: ");
		while (optind < argc) {
			if (! infile) { infile=argv[optind]; program_flag=1; }
			if (verbose>4) printf ("%s ", argv[optind]);
			optind++;
		}
		if (verbose>4) printf ("\n");
	}
	
	if (verbose>4) printf("Infile: %s\n",infile);
	if (program_flag==0 && console_flag==0) usage();
	//if (verbose>5) exit(0); // cmd line parsing testing
	
	BS2_comm_init();
	rval=1;
	if (program_flag) rval=program_stamp();
	
	if (rval && console_flag) {
		if (program_flag==0 && reset_flag==1) BS2_reset();
		console();
		rval=0;
	}
	BS2_comm_halt();
	return rval;
}

void version(void) {
	fprintf(stderr, "$Revision: 1.15 $ \n current filename: ");
	fprintf(stderr, __FILE__);
	fprintf(stderr, "\n");
	exit(0);
}

void usage(void) {
	// TODO: update wordy text for new flags & behavior
	fprintf(stderr, "\nBasic Stamp Linux Programmer / Debugger\n\n");
	fprintf(stderr, "This program is used to program and run a basic stamp.\n");
	fprintf(stderr, "Before it can be used, some simple setup must be done (see below).\n");
	fprintf(stderr, "For more information about the Basic Stamp, see http://www.parallax.com\n\n");
	fprintf(stderr, "This is a modified version of bstamp available at http://bstamp.sourceforge.net\n");
	fprintf(stderr, "Options:\n");
	fprintf(stderr, "\t-h or -? : this help listing\n");
	fprintf(stderr, "\t-v : the program version\n");
	fprintf(stderr, "\t-V : verbose\n");
	fprintf(stderr, "\t-c : do debug console\n");
	fprintf(stderr, "\t-A : ANSI terminal codes (translate cursor controls)\n");
	fprintf(stderr, "\t-r : if console only, reset device prior to console mode\n");
	fprintf(stderr, "\t-p : program device\n");
	fprintf(stderr, "\t-d : communications device (default /dev/bstamp)\n");
	fprintf(stderr, "\t-s : use stdin instead of INFILE.TOK\n");
	fprintf(stderr, "\t-f : filename INFILE.TOK (-f optional)\n");
	fprintf(stderr, "\talternately, to use stdin do not include any other arguments.\n\n");
	fprintf(stderr, "The basic stamp must be plugged into a local serial (COM) port.\n");
	fprintf(stderr, "Examples here use /dev/ttyS0 as the serial port,.\n");
	fprintf(stderr, " but you may need to use something else (like /dev/ttyS1).\n");
	fprintf(stderr, "A symlink named 'bstamp' in /dev must point to the com port you wish to use.\n");
	fprintf(stderr, "This can be done with 'ln -s /dev/ttyS0 /dev/bstamp'.\n");
	fprintf(stderr, "If the serial port doesn't work, you might try 'MAKEDEV /dev/ttyS0'\n");
	fprintf(stderr, "You may need to be root to accomplish this, try 'su' to become root.\n");
	fprintf(stderr, "When done with MAKEDEV and creating the symlink, type exit.\n\n");
	fprintf(stderr, "You must include a tokenized program when calling this program.\n");
	fprintf(stderr, "First run 'bstamp_tokenize INFILE.TXT OUTFILE.TOK' to make the tokenized program.\n");
	fprintf(stderr, "Next run 'cat INFILE.TOK | bstamp_run'\n\n");
	fprintf(stderr, "Standard Usage: bstamp_run INFILE.TOK\n");
	fprintf(stderr, " Or:\n cat INFILE.TOK | bstamp_run\n Or:\n cat INFILE.BS2 | bstamp_tokenizer | bstamp_run\n");
	exit(0);
}

int program_stamp(void) {
	int rval;
	if (BS2_id())
	{
		fprintf(stderr, "Basic Stamp detected!\n");
		fprintf(stderr, "Model: %s\n", model_names[model]);
		fprintf(stderr, "Firmware version in BCD = %.1f\n", firmware_version);
		if (infile) rval=BS2_sendfile(infile);
		else rval=BS2_sendfile();
		//do_console=1; // now we know the stamp is programmed do debug console
		if (rval) return(1);
		return(0);
	}
	else
	{
		fprintf(stderr, "Error: No BASIC Stamp identified!\n");
		fprintf(stderr, "Probably the stamp isn't connected, perhaps your stamp version isn't supported?\n");
		fprintf(stderr, "Try looking at the help, try '");
		fprintf(stderr, prog_name);
		fprintf(stderr, " -h' for more information.\n");
		return(0);
	}
}





void BS2_comm_init() {
  /*
	setup timeout handlers,
	save com port settings,
	set com port settings
  */

	/* catch timeouts */
	signal(SIGALRM,(sighandler_t)timeout_handler);
	alarm(0);

	/* open COM port */
	fd=open(device,O_RDWR | O_NOCTTY);
	if(fd<0){
		fprintf(stderr, "Error: Could not open %s for reading/writing!\n",device);
		exit(STATE_CRITICAL);
	        }

	/* save current COM port settings */
	tcgetattr(fd,&oldtios);

	/* set new COM port settings */
	newtios.c_cflag=B9600 | CS8 | CLOCAL | CREAD;
	newtios.c_iflag=IGNPAR;
	newtios.c_oflag=0;
	newtios.c_lflag=0;
	newtios.c_line=0;
	newtios.c_cc[VMIN]=0;
	newtios.c_cc[VTIME]=5;
	tcsetattr(fd,TCSANOW,&newtios);

}

void BS2_comm_halt(void)
{

	fprintf(stderr, "\nShutting down communication!\n");

	/* restore original COM port settings and close it */
	tcsetattr(fd,TCSANOW,&oldtios);
	close(fd);

	/* reset alarm */
	alarm(0);
}

void BS2_reset()
{
  /*
  	DTR & Tx High for 2ms,
	DTR Low & Tx High for 36 ms,
	DTR & Tx Low for 20 ms,
	Flush buffer
  */

  	int dtr_flag;

	/* From BASIC Stamp Programming Protocol, page 5: */

	/* 1. set DTR high */
	dtr_flag = TIOCM_DTR;
	ioctl(fd, TIOCMBIS, &dtr_flag);

	/* 2. Set break condition on TX */
	ioctl(fd, TIOCSBRK, 4);

	/* 3. Pause for at least 2 ms: */
	usleep(2000);

	/* 4. Set DTR low: */
	dtr_flag = TIOCM_DTR;
	ioctl(fd, TIOCMBIC, &dtr_flag);

	/* 5. Pause for at least 36 ms: */
	usleep(36000);

	/* 6. Clear break condition on TX */
	ioctl(fd, TIOCCBRK, 4);

	/* 7. Pause for approximately 20 ms */
	usleep(20000);

	/* ... and flush receive buffer: */
	tcflush(fd,TCIFLUSH);
}

int BS2_id(void)
{
  /*
  	reset the stamp,
	try the various stamp recognition sequences,
	set the type and version,
	return 1 if good, 0 otherwise
  */

	char snd[] = {'e','X','P','I'};
	int count = 0;	
	char tempChar;
  	model = MODEL_UNKNOWN;
	firmware_version = -1;

	BS2_reset();
	
	/* check for BS2 */
	if (BS2_send_bytes('B') == char(190)) // 2s compliment = (-'B'&0xff)
	{
		if (BS2_send_bytes('S') == char(173))
		{
			if (BS2_send_bytes('2') == char(206))
			{
				firmware_version = (float) BS2_send_bytes(0);
				firmware_version  = (firmware_version / 10);
				model = MODEL_BS2;
			}
		}
		else
			return 0;
	}

	if ( model == MODEL_UNKNOWN )
	{
		do{
			BS2_reset();

			tempChar = BS2_send_bytes(snd[count]);

			set_firmware(tempChar);
			set_model(tempChar);
		
			count++;

		}while(model == MODEL_UNKNOWN && count < 3);
	}

	if ( model == MODEL_UNKNOWN )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/*
void BS2_write(char * str)
{
  if (write(fd,str,strlen(str)) )
  {
	#ifdef DEBUG
		fprintf(stderr, "Write succeeded [ %s ]\n", str);
	#endif
  }
  usleep(20000);
}
*/

char BS2_send_bytes(char snd)
{
	/* Send the identification request character */
	if (write(fd,&snd,1))
	{
		if (verbose>3) printf("Wrote to Stamp: %c\n", snd);
	}

	/* Enable timeout alarm: */
	alarm(timeout);

	/* Receive and discard echo: */
	BS2_read(recvbuf, 1);
	BS2_read(recvbuf, 1);
	/* Disable timeout alarm: */
	alarm(0);
	
	return recvbuf[0];
}

void BS2_read(char * str, int count)
{
  int i, num_got;
  char chr;

  num_got = 0;

  for (i = 0; i < count; i++)
  {
    if (!read(fd,&chr,1))
	{
	  str[i] = '\0';
	}
	else
	{
	  str[i] = chr;
	  num_got++;
	}
  }

  str[i] = '\0';

  if (verbose>3) {
	fprintf(stderr, "RECEIVED %d BYTES:  %s\n", num_got, str);
	for (i = 0; i < num_got; i++)
	{
	  fprintf(stderr, "%4d = %d\n", i, (unsigned char) str[i]);
	}
	fprintf(stderr, "\n");
  }
}

/* sets stamp model name*/ 
void set_model(char detect)
{
   switch (detect)
   {		
	   case 'B':
		  model = MODEL_BS2;
		  break;
	   
	   case 'X': case 'Y': case 'Z':
		  model = MODEL_BS2sx;
		  break;
	   
	   case 'e':
		  model = MODEL_BS2e;
		  break;
			
	   case 'p': case 'q': case 'r': case 's':
		  model = MODEL_BS2p24;
		  break;
			
	   case 'P': case 'Q': case 'R': case 'S':
		  model = MODEL_BS2p40;
		  break;
			
	   case 'i': case 'j': case 'k':
		  model = MODEL_BS2pe24;
		  break;
			
	   case 'I': case 'J': case 'K':
		  model = MODEL_BS2pe40;
		  break;
			
	   default:
		 printf("Error: Unknown Model. Please inform the developers.\n");
		 exit(1);
		 break;
	}
}

/* set the Firmware version based on char */
void set_firmware(char fid)
{
	switch (fid)
	{
		case 'e': case 'i': case 'I': case 'P': case 'p': case 'X': 
			firmware_version = 1.0;
			break;
		case 'j': case 'J': case 'q': case 'Q': case 'Y': 
			firmware_version = 1.1;
			break;
		case 'k': case 'K': case 'r': case 'R': case 'Z': 
			firmware_version = 1.2;
			break;
		case 's': case 'S':
			firmware_version = 1.3;
			break;
		default:
			printf("Error: Unknown firmware version. Please inform the developers\n");
			exit(1);
			break;
	}
}

int BS2_sendfile() {
	return BS2_sendfile(fileno(stdin));
}

int BS2_sendfile(char * fname) {
	int in_fd;
	int rval;
	in_fd = open(fname, O_RDONLY);
	if (in_fd == -1)
	{
		fprintf(stderr, "Error loading %s!\n", fname);
		exit(1);
	}
	rval=BS2_sendfile(in_fd);
	close(in_fd);
	return(rval);
}


int BS2_sendfile(int in_fd)
{
  int num_read;
  int num_write;
  unsigned char buf[18];
  unsigned char recvbuf[18];
  unsigned char recvchar;

  if (verbose<2) fprintf(stderr, "Programming");
  if (verbose<1) fprintf(stderr, "...");
  // non-BS2 needs slot support
  if (model!=MODEL_BS2)
  {
	unsigned char program_slot=0;
	write(fd, &program_slot, 1); // send program slot
	tcflush(fd,TCIFLUSH);
	usleep(500000);
  }
	//fcntl(fd,F_SETFD,O_FSYNC);
	do
	{
		num_read = read(in_fd, buf, 18);
		if (verbose>3) fprintf(stderr, "Read %d bytes from file...\n", num_read);

		if (num_read > 0)
		{
			// send 18-byte packet
			num_write=TEMP_FAILURE_RETRY (write(fd, buf, num_read));
			if (verbose>3) fprintf(stderr, "%d characters transmitted\n", num_write);

			tcflush(fd,TCIFLUSH);
			usleep(500000);

			int read_sz=read(fd, recvbuf, num_read); // read and discard 18-byte packet

			if (verbose>3) fprintf(stderr, "%d characters echoed\n",read_sz);
			read_sz=read(fd, &recvchar, 1); // read ack byte
			if (verbose>3) fprintf(stderr, "Ack = %d\n", recvchar);
			if (verbose==1) fprintf(stderr, ".");

			if ( recvchar != 0) error_handler(recvchar);
		}
	}
	while (num_read > 0);
  if (verbose==1) fprintf(stderr, "\n");
  if (verbose<2) fprintf(stderr, "Done.\n");
return(1);
}

void error_handler(char recv)
{
	switch(recv)
	{
		case 1:
			fprintf(stderr, "Ack = %d\n", recv); // print ack byte
			fprintf(stderr, "Error: Communication error while programming stamp, try again\n");
			break;
		case 2:
			fprintf(stderr, "Ack = %d\n", recv); // print ack byte
			fprintf(stderr, "Error: EEPROM error.\n");
			fprintf(stderr, "If this happens consistently, there may be a problem with your stamp.\n");
			break;
		default:
			fprintf(stderr, "Ack = %d\n", recv); // print ack byte
			fprintf(stderr, "Error: Unknown error while programming stamp!\n");
			break;
	}

	exit(1);
}

/* handle timeouts */
void *timeout_handler(int sig){

  fprintf(stderr, "ERROR: Timed out waiting for data from %s\n", device);

  //tcsetattr(fd,TCSANOW,&oldtios);
  //close(fd);

  //exit(STATE_CRITICAL);

  return NULL;
}

int console_loop_done;
void console(void)
{
	char recvchar;
	int num_read=0;

	console_loop_done=0;

	fprintf(stderr, "DEBUG OUTPUT:     (Press [Control]-[C] to complete sequence)\n");
	fprintf(stderr, "_____________________________________________________________________\n");
	fflush(stderr);

	signal(SIGINT,(sighandler_t)control_c_handler);
	alarm(0);

	// Turn off blocking on the fileno belonging to STDIN
	fcntl(fileno(stdin), F_SETFL, O_NONBLOCK);

        do
	{
	  if (read(fd, &recvchar, 1))
	  {
	    // Do a bit of terminal emulation
	    // TODO:
	    //   1) Commandline Param to do add LF to CR automatically
	    if (ANSI_flag) {
	    switch(recvchar) {
		    case 0x00: // - CLS - clear screen move cursor top left
			    printf("\033[2J\033[H"); // could fall through to HOME, but this is clearer
			    break; 
		    case 0x01: // - HOME - move cursor top left
			    printf("\033[H"); 
			    break;
		    case 0x02: // - CRSRXY - move cursor x, y
			    read(fd, recvbuf, 2); 
			    printf("\033[%d;%dH", recvbuf[1], recvbuf[0]);
			    break;
		    case 0x03: // - CRSRLF - move cursor left
			    printf("\033[1D"); 
			    break;
		    case 0x04: // - CRSRRT - move cursor right
			    printf("\033[1C"); 
			    break;
		    case 0x05: // - CRSRUP - move cursor up
			    printf("\033[1A"); 
			    break;
		    case 0x06: // - CRSRDN - move cursor down
			    printf("\033[1B"); 
			    break;
		    case 0x07: // - BELL - Beep the PC speaker
	      		    printf("%c", recvchar);
			    break;
		    case 0x08: // - BKSP - Backspace
	      		    printf("%c", recvchar);
			    break;
		    case 0x09: // - TAB - Tab to next column
	      		    printf("%c", recvchar);
			    break;
		    case 0x0a: // - LF - Linefeed - Move cursor down one line 
			    // HACK - EOL is platform specific, and is generally translated by the native compiler
			    // HACK -   Unix EOL = LF
			    // HACK -   Mac  EOL = CR
			    // HACK -   Win  EOL = CRLF
			    // HACK -   Since most platforms translate EOL to CRLF equivelent
			    // HACK -   I use ANSI sequence to display LF w/o CR
			    printf("\033[1B"); // do a console LF (no CR) 
	      		    //printf("%c", recvchar); // raw output
			    //printf("\n"); 
			    break;
		    case 0x0b: // - CLREOL - Clear to end of line
			    printf("\033[K"); 
			    break;
		    case 0x0c: // - CLRDN - Clear Screen to end of line, and below cursor
			    printf("\033[J"); 
			    break;
		    case 0x0d: // - CR - move to beginning of same line
			    //printf("\r"); 
	      		    printf("%c", recvchar);
			    //printf("\r\n"); // Take into account DOS EOL
			    break;
		    case 0x0e: // - CRSRX - move to specified column
			    // HACK - No ANSI sequence for CRSRX
			    //printf("\033[%d;H", recvbuf[0]);
			    read(fd, recvbuf, 1); 
			    printf("\033[200D\033[%dC", recvbuf[0]);
			    break;
		    case 0x0f: // - CRSRY - move to specified row
			    // HACK - No ANSI sequence for CRSRY
			    //printf("\033[;%dH", recvbuf[0]);
			    read(fd, recvbuf, 1); 
			    printf("\033[200A\033[%dB", recvbuf[0]);
			    break;
		    default:
	    		    if (isprint(recvchar)) { // printable
	      			printf("%c", recvchar);
	    		    } else {		     // unknown
				// TODO use BASIC HEX indicator instead of % prefix here
	      			printf("%%%02X",recvchar);
	    		    }
			    break;
	    } //end switch
	    } else {
		printf("%c", recvchar);
		if (recvchar == '\r' && eol_flag) printf("\n"); /* Take into account DOS EOL: */
	    } // end if console

	    fflush(stdout);
	  } // end if read

	  // TODO !!!
	  // ADD THE ABILITY TO COMBINE STDIN FROM THE KEYBOARD TO THE DEBUGGER
	  // 	TO HAVE COMMAND-LINE DEBUGGER STAMP INTERACTION
	  // THIS CODE IS CURRENTLY NON-FUNCTIONAL. THE IDEA WAS TO USE IT AS FOLLOWS:
	  //	cat hw.bs2 | ./bstamp_tokenize | ./bstamp_run <&0
	  // TO APPEND THE STDIN TO THE bstamp_runu command.
	  //
	  // It does now however work in this invocation:
	  //	cat hw.bs2 | ./bstamp_tokenize >prog.tok && ./bstamp_run prog.tok
	  //

	  if (num_read=fread(sendbuf, 1, BUFFER_SIZE, stdin)) // COMMUNICATE BACK TO STAMP
	  {
			write(fd, sendbuf, num_read);
			tcflush(fd,TCIFLUSH);
			// 1/2 second is way too long.  commenting it out had no adverse effects.
			// this is not to say some sleep() or select() wouldn't be a good idea.
			// usleep(500000); 
			BS2_read(recvbuf, num_read); // read and trash echo
	  }
	}
        while (!console_loop_done);

	/* Complete sequence: */
	write(fd, "\0", 1);
}


/* handle control c */
void *control_c_handler(int sig)
{

	fflush(stdout);
	fflush(stderr);

	fprintf(stderr, "\n_____________________________________________________________________\n");
	fprintf(stderr, "\nReceived [Control]-[C]!\n");
	fflush(stderr);

	console_loop_done = 1;
	return NULL;
}

/*
 * main.cpp
 *
 *  Created on: Mar 1, 2011
 *      Author: mark
 */
#include "main.h"
#include <dlfcn.h>
#include <stdio.h>
void main(){
	   void *lib_handle;
	   double (*fn)(int *);
	   int x;
	   char *error;

	   lib_handle = dlopen("/libctest.so", RTLD_LAZY);
	   if (!lib_handle)
	   {
	      fprintf(stderr, "%s\n", dlerror());
	      exit(1);
	   }

	   fn = dlsym(lib_handle, "ctest1");
	   if ((error = dlerror()) != NULL)
	   {
	      fprintf(stderr, "%s\n", error);
	      exit(1);
	   }

	   (*fn)(&x);
	   printf("Valx=%d\n",x);

	   dlclose(lib_handle);
	   return 0;
}

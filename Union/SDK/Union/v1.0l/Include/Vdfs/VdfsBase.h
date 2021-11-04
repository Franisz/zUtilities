#pragma once

#ifndef VDFS32G

// open file and return handle
VDFAPI long32 vdf_fopen (text fullfname, long32 flags);


// close file
VDFAPI long32 vdf_fclose (long32 handle);


// read file to the buffer. return the real readed size in bytes
VDFAPI long32 vdf_fread (long32 handle, HBuffer buffer, long32 size);


// move the reading cursor to specified position
VDFAPI long32 vdf_fseek (long32 handle, long32 pos);


// get the reading cursor
VDFAPI long32 vdf_ftell (long32 handle);


// check the file by full name. flags - is prefer file mode - physical 
// or virtual. if choose both, system will return the highest-priority 
// flag of the file. or Null if file does not exists.
VDFAPI long32 vdf_fexists (text fullfname, long32 flags);


// finds files by relative path. second argument - the
// found fullname if return value is not false.
VDFAPI long32 vdf_searchfile (text filename, text fullfilename);


// return size of file
VDFAPI long32 vdf_ffilesize (long32 handle);


// for union vdfs this parms unused
VDFAPI long32 vdf_initall (long32 numdisks = None, text cdid = None, long32* cddrives = None, long32* disksfound = None);


VDFAPI long32 vdf_registerkey(char* volName, char* longKey128);


#include "VdfsAPI\vdfsTypes.h"
#include "VdfsAPI\Vdfs32.h"

#else

// open file and return handle
extern long32 vdf_fopen (text fullfname, long32 flags);


// close file
extern long32 vdf_fclose (long32 handle);


// read file to the buffer. return the real readed size in bytes
extern long32 vdf_fread (long32 handle, HBuffer buffer, long32 size);


// move the reading cursor to specified position
extern long32 vdf_fseek (long32 handle, long32 pos);


// get the reading cursor
extern long32 vdf_ftell (long32 handle);


// check the file by full name. flags - is prefer file mode - physical 
// or virtual. if choose both, system will return the highest-priority 
// flag of the file. or Null if file does not exists.
extern long32 vdf_fexists (text fullfname, long32 flags);


// finds files by relative path. second argument - the
// found fullname if return value is not false.
extern long32 vdf_searchfile (text filename, text fullfilename);


// return size of file
extern long32 vdf_ffilesize (long32 handle);


// for union vdfs this parms unused
extern long32 vdf_initall (long32 numdisks = None, text cdid = None, long32* cddrives = None, long32* disksfound = None);

#endif
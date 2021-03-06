/*  
* Copyright (c) 2011-2013, NVIDIA Corporation
* All rights reserved.
*  
* Redistribution and use in source and binary forms, with or without  
* modification, are permitted provided that the following conditions are met:  
*   * Redistributions of source code must retain the above copyright  
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above copyright  
*     notice, this list of conditions and the following disclaimer in the  
*     documentation and/or other materials provided with the distribution.  
*   * Neither the name of NVIDIA Corporation nor the  
*     names of its contributors may be used to endorse or promote products  
*     derived from this software without specific prior written permission.  
*  
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND  
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  
* DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY  
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
*/ 

// SHJCGT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

using namespace std;

extern void BuildSHEvalCode(string &sResult, const unsigned int lmax);

int _tmain(int argc, _TCHAR* argv[])
{
    FILE *f = nullptr;
    
    fopen_s(&f, argv[1],"wb");

   for(unsigned int ii=2;ii<=9;ii++) {
      string sTmp;
      BuildSHEvalCode(sTmp,ii);
      fprintf(f,"// order %d\n%s\n",ii+1,sTmp.c_str());
   }

   fclose(f);

	return 0;
}


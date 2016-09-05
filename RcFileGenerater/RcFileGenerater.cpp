// RcFileGenerater.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include<iostream>
#include<fstream>
#include <ctime>
using namespace std;

int main()
{

	char * _fileMajor = (char *)malloc(MAX_PATH*sizeof(char));
	char * _fileMinor = (char *)malloc(MAX_PATH*sizeof(char));
	char * productName = (char *)malloc(MAX_PATH*sizeof(char));
	char * _productMajor = (char *)malloc(MAX_PATH*sizeof(char));
	char * _productMinor = (char *)malloc(MAX_PATH*sizeof(char));
	char * author = (char *)malloc(MAX_PATH*sizeof(char));
	char * dir = (char *)malloc(MAX_PATH*sizeof(char));
	char * fileName1 = (char *)malloc(MAX_PATH*sizeof(char));
	char * fileName2 = (char *)malloc(MAX_PATH*sizeof(char));
	char * fileName3 = (char *)malloc(MAX_PATH*sizeof(char));

	printf("\nInput the where files will generate = ?");
	fgets(dir, MAX_PATH, stdin);
	if (dir[strlen(dir) - 1] == '\n'){
		dir[strlen(dir) - 1] = '\0';
	}
	sprintf(fileName1,"%s\\resource2.h", dir);
	sprintf(fileName2,"%s\\version.rc", dir);
	sprintf(fileName3,"AssemblyInfo.cs");

    fstream fp;
    fp.open(fileName1, ios::out);
    if(!fp){
        printf("Fail to open file: %s\n", fileName1);
		fp.close();
		return -1;
	}else{
		fp<<"#ifdef APSTUDIO_INVOKED"<<endl;
		fp<<"#ifndef APSTUDIO_READONLY_SYMBOLS"<<endl;
		fp<<"#define _APS_NEXT_RESOURCE_VALUE        101"<<endl;
		fp<<"#define _APS_NEXT_COMMAND_VALUE         40001"<<endl;
		fp<<"#define _APS_NEXT_CONTROL_VALUE         1001"<<endl;
		fp<<"#define _APS_NEXT_SYMED_VALUE           101"<<endl;
		fp<<"#endif"<<endl;
		fp<<"#endif"<<endl;
		printf("%s is generated!\n", fileName1);
		fp.close();
	}

	printf("\nInput file.Major = ?");
	fgets(_fileMajor, MAX_PATH, stdin);
	if (_fileMajor[strlen(_fileMajor) - 1] == '\n'){
		_fileMajor[strlen(_fileMajor) - 1] = '\0';
	}
	
	printf("\nInput file.Minor = ?");
	fgets(_fileMinor, MAX_PATH, stdin);
	if (_fileMinor[strlen(_fileMinor) - 1] == '\n'){
		_fileMinor[strlen(_fileMinor) - 1] = '\0';
	}

	printf("\nInput product name = ?");
	fgets(productName, MAX_PATH, stdin);
	if (productName[strlen(productName) - 1] == '\n'){
		productName[strlen(productName) - 1] = '\0';
	}

	printf("\nInput product.Major = ?");
	fgets(_productMajor, MAX_PATH, stdin);
	if (_productMajor[strlen(_productMajor) - 1] == '\n'){
		_productMajor[strlen(_productMajor) - 1] = '\0';
	}
	
	printf("\nInput product.Minor = ?");
	fgets(_productMinor, MAX_PATH, stdin);
	if (_productMinor[strlen(_productMinor) - 1] == '\n'){
		_productMinor[strlen(_productMinor) - 1] = '\0';
	}

	printf("\nInput author = ?");
	fgets(author, MAX_PATH, stdin);
	if (author[strlen(author) - 1] == '\n'){
		author[strlen(author) - 1] = '\0';
	}
	
	struct tm a = {0,0,0,1,1,100}; /* Jan 1, 2000 */
	int difference  = 0;
	time_t t = std::time(NULL);
	tm  now = *std::localtime( & t );
	now.tm_year = now.tm_year ;
	now.tm_mon = now.tm_mon ;

	int Revision = ((int) (now.tm_sec + now.tm_min * 60 + now.tm_hour * 60 * 60 )/2 );

	time_t x = std::mktime(&a);
	time_t y = std::mktime(&now);
	if ( x != (std::time_t)(-1) && y != (std::time_t)(-1) )
	{
		difference = ( difftime(y, x) / (60 * 60 * 24) + 1);	
	}
	fstream fp2;
    fp2.open(fileName2, ios::out);
    if(!fp2){
        printf("Fail to open file: %s\n", fileName2);
		fp2.close();
		return -1;
	}else{
		fp2<<"#include \"resource2.h\""<<endl;
		fp2<<"#define APSTUDIO_READONLY_SYMBOLS"<<endl;
		fp2<<"#include \"afxres.h\""<<endl;
		fp2<<"#undef APSTUDIO_READONLY_SYMBOLS"<<endl;
		fp2<<"#if !defined(AFX_RESOURCE_DLL) || defined(AFX_TARG_CHT)"<<endl;
		fp2<<"#ifdef _WIN32"<<endl;
		fp2<<"LANGUAGE LANG_CHINESE, SUBLANG_CHINESE_TRADITIONAL"<<endl;
		fp2<<"#pragma code_page(950)"<<endl;
		fp2<<"#endif //_WIN32"<<endl;
		fp2<<"#ifdef APSTUDIO_INVOKED"<<endl;

		fp2<<"1 TEXTINCLUDE "<<endl;
		fp2<<"BEGIN"<<endl;
		fp2<<"    \"resource2.h\\0\""<<endl;
		fp2<<"END"<<endl;

		fp2<<"2 TEXTINCLUDE "<<endl;
		fp2<<"BEGIN"<<endl;
		fp2<<"    \"#include \"\"afxres.h\"\"\\r\\n\""<<endl;
		fp2<<"    \"\\0\""<<endl;
		fp2<<"END"<<endl;

		fp2<<"3 TEXTINCLUDE "<<endl;
		fp2<<"BEGIN"<<endl;
		fp2<<"    \"\\r\\n\""<<endl;
		fp2<<"    \"\\0\""<<endl;
		fp2<<"END"<<endl;

		fp2<<"#endif    // APSTUDIO_INVOKED"<<endl;

		fp2<<"1 VERSIONINFO"<<endl;
 		fp2<<"FILEVERSION "<<_fileMajor<<","<<_fileMinor<<","<<difference<<","<<Revision<<endl;
 		fp2<<"PRODUCTVERSION "<<_productMajor<<","<<_productMinor<<","<<difference<<","<<Revision<<endl;
 		fp2<<"FILEFLAGSMASK 0x0L"<<endl;
		fp2<<"#ifdef _DEBUG"<<endl;
		fp2<<" FILEFLAGS 0x21L"<<endl;
		fp2<<"#else"<<endl;
		fp2<<" FILEFLAGS 0x20L"<<endl;
		fp2<<"#endif"<<endl;
		fp2<<" FILEOS 0x4L"<<endl;
		fp2<<" FILETYPE 0x1L"<<endl;
		fp2<<" FILESUBTYPE 0x0L"<<endl;
		fp2<<"BEGIN"<<endl;
		fp2<<"    BLOCK \"StringFileInfo\""<<endl;
		fp2<<"    BEGIN"<<endl;
		fp2<<"        BLOCK \"040904b0\""<<endl;
		fp2<<"        BEGIN"<<endl;
		fp2<<"            VALUE \"CompanyName\", "<<"\""<<author<<"\""<<endl;
		fp2<<"            VALUE \"FileDescription\", \"\""<<endl;
		fp2<<"            VALUE \"FileVersion\", \""<<_fileMajor<<","<<_fileMinor<<","<<difference<<","<<Revision<<"\""<<endl;
		fp2<<"            VALUE \"LegalCopyright\", \"Copyright (c) 2009, "<<author<<"\""<<endl;
		fp2<<"            VALUE \"OriginalFilename\", \"\""<<endl;
   
		fp2<<"         VALUE \"ProductName\", \""<<productName<<"\""<<endl;
		fp2<<"            VALUE \"ProductVersion\", \""<<_productMajor<<","<<_productMinor<<","<<difference<<","<<Revision<<"\""<<endl;
		fp2<<"        END"<<endl;
		fp2<<"    END"<<endl;
		fp2<<"    BLOCK \"VarFileInfo\""<<endl;
		fp2<<"    BEGIN"<<endl;
		fp2<<"        VALUE \"Translation\", 0x409, 1200"<<endl;
		fp2<<"    END"<<endl;
		fp2<<"END"<<endl;

		fp2<<"#endif    // Chinese (Taiwan) resources"<<endl;
		fp2<<"#ifndef APSTUDIO_INVOKED"<<endl;
		fp2<<"#endif    // not APSTUDIO_INVOKED"<<endl;
		printf("%s is generated!\n", fileName2);
		fp2.close();
		
	}
	
    fstream fp3;
    fp3.open(fileName3, ios::out);
	if(!fp3){
        printf("Fail to open file: %s\n", fileName3);
		fp3.close();
		return -1;
	}else{
		fp3<<"[assembly: AssemblyVersion(\""<<_fileMajor<<"."<<_fileMinor<<"."<<difference<<"."<<Revision<<"\""<<")]"<<endl;
		fp3<<"[assembly: AssemblyFileVersion(\""<<_productMajor<<"."<<_productMinor<<"."<<difference<<"."<<Revision<<"\""<<")]"<<endl;
		printf("%s is generated!\n", fileName3);
	}

	free(_fileMajor);
	free(_fileMinor);
	free(productName);
	free(_productMajor);
	free(_productMinor);
	free(author);
	free(dir);
	free(fileName1);
	free(fileName2);
	free(fileName3);
	return 0;
}

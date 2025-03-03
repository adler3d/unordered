#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>

#define to_out(...){char buff[1024]={0}; sprintf_s(buff,__VA_ARGS__); g_out+=string(buff);}

struct t_proc_list{
  static BOOL GetProcessList(string&g_out, string*killtarget=nullptr)
  {
    HANDLE hProcessSnap;
    HANDLE hProcess;
    PROCESSENTRY32 pe32;
    DWORD dwPriorityClass;

    // Take a snapshot of all processes in the system.
    hProcessSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
    if( hProcessSnap == INVALID_HANDLE_VALUE )
    {
      printError(g_out, TEXT("CreateToolhelp32Snapshot (of processes)") );
      return( FALSE );
    }

    // Set the size of the structure before using it.
    pe32.dwSize = sizeof( PROCESSENTRY32 );

    // Retrieve information about the first process,
    // and exit if unsuccessful
    if( !Process32First( hProcessSnap, &pe32 ) )
    {
      printError(g_out, TEXT("Process32First") ); // show cause of failure
      CloseHandle( hProcessSnap );          // clean the snapshot object
      return( FALSE );
    }

    // Now walk the snapshot of processes, and
    // display information about each process in turn
    do
    {
      if(0){
      to_out( TEXT("\n\n=====================================================" ));
      to_out( TEXT("\nPROCESS NAME:  %s"), pe32.szExeFile );
      to_out( TEXT("\n-------------------------------------------------------" ));
      };

      // Retrieve the priority class.
      dwPriorityClass = 0;
      hProcess = OpenProcess( PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID );

      if(killtarget&&string(pe32.szExeFile)==*killtarget){
        TerminateProcess(hProcess,0);
      }

      if( hProcess == NULL )      {
        //printError(g_out, TEXT("OpenProcess") );
      }else{
        dwPriorityClass = GetPriorityClass( hProcess );
        if( !dwPriorityClass )
          printError(g_out, TEXT("GetPriorityClass") );
        CloseHandle( hProcess );
      }

      if(0){
      to_out( TEXT("\n  Process ID        = 0x%08X"), pe32.th32ProcessID );
      to_out( TEXT("\n  Thread count      = %d"),   pe32.cntThreads );
      to_out( TEXT("\n  Parent process ID = 0x%08X"), pe32.th32ParentProcessID );
      to_out( TEXT("\n  Priority base     = %d"), pe32.pcPriClassBase );
      }else{
        to_out( TEXT("\nPID = 0x%08X;    Parent = 0x%08X;    TC = %03d;    PB = %02d;    PC = %08d;    NAME = %s"), pe32.th32ProcessID, pe32.th32ParentProcessID, pe32.cntThreads, pe32.pcPriClassBase, dwPriorityClass, pe32.szExeFile );
      }

      if( dwPriorityClass )
        //to_out( TEXT("\n  Priority class    = %d"), dwPriorityClass );
      if(0){
      // List the modules and threads associated with this process
        ListProcessModules(g_out, pe32.th32ProcessID );
        ListProcessThreads(g_out, pe32.th32ProcessID );
      }
    } while( Process32Next( hProcessSnap, &pe32 ) );

    CloseHandle( hProcessSnap );
    return( TRUE );
  }

  static BOOL ListProcessModules(string&g_out, DWORD dwPID )
  {
    HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
    MODULEENTRY32 me32;

    // Take a snapshot of all modules in the specified process.
    hModuleSnap = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, dwPID );
    if( hModuleSnap == INVALID_HANDLE_VALUE )
    {
      printError(g_out, TEXT("CreateToolhelp32Snapshot (of modules)") );
      return( FALSE );
    }

    // Set the size of the structure before using it.
    me32.dwSize = sizeof( MODULEENTRY32 );

    // Retrieve information about the first module,
    // and exit if unsuccessful
    if( !Module32First( hModuleSnap, &me32 ) )
    {
      printError(g_out, TEXT("Module32First") );  // show cause of failure
      CloseHandle( hModuleSnap );           // clean the snapshot object
      return( FALSE );
    }

    // Now walk the module list of the process,
    // and display information about each module
    do
    {
      to_out( TEXT("\n\n     MODULE NAME:     %s"),   me32.szModule );
      to_out( TEXT("\n     Executable     = %s"),     me32.szExePath );
      to_out( TEXT("\n     Process ID     = 0x%08X"),         me32.th32ProcessID );
      to_out( TEXT("\n     Ref count (g)  = 0x%04X"),     me32.GlblcntUsage );
      to_out( TEXT("\n     Ref count (p)  = 0x%04X"),     me32.ProccntUsage );
      to_out( TEXT("\n     Base address   = 0x%08X"), (DWORD) me32.modBaseAddr );
      to_out( TEXT("\n     Base size      = %d"),             me32.modBaseSize );

    } while( Module32Next( hModuleSnap, &me32 ) );

    CloseHandle( hModuleSnap );
    return( TRUE );
  }

  static BOOL ListProcessThreads(string&g_out, DWORD dwOwnerPID ) 
  { 
    HANDLE hThreadSnap = INVALID_HANDLE_VALUE; 
    THREADENTRY32 te32; 
 
    // Take a snapshot of all running threads  
    hThreadSnap = CreateToolhelp32Snapshot( TH32CS_SNAPTHREAD, 0 ); 
    if( hThreadSnap == INVALID_HANDLE_VALUE ) 
      return( FALSE ); 
 
    // Fill in the size of the structure before using it. 
    te32.dwSize = sizeof(THREADENTRY32); 
 
    // Retrieve information about the first thread,
    // and exit if unsuccessful
    if( !Thread32First( hThreadSnap, &te32 ) ) 
    {
      printError(g_out, TEXT("Thread32First") ); // show cause of failure
      CloseHandle( hThreadSnap );          // clean the snapshot object
      return( FALSE );
    }

    // Now walk the thread list of the system,
    // and display information about each thread
    // associated with the specified process
    do 
    { 
      if( te32.th32OwnerProcessID == dwOwnerPID )
      {
        to_out( TEXT("\n\n     THREAD ID      = 0x%08X"), te32.th32ThreadID ); 
        to_out( TEXT("\n     Base priority  = %d"), te32.tpBasePri ); 
        to_out( TEXT("\n     Delta priority = %d"), te32.tpDeltaPri ); 
        to_out( TEXT("\n"));
      }
    } while( Thread32Next(hThreadSnap, &te32 ) ); 

    CloseHandle( hThreadSnap );
    return( TRUE );
  }

  static void printError(string&g_out, TCHAR* msg )
  {
    DWORD eNum;
    TCHAR sysMsg[256];
    TCHAR* p;

    eNum = GetLastError( );
    FormatMessage( FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
           NULL, eNum,
           MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
           sysMsg, 256, NULL );

    // Trim the end of the line and terminate it with a null
    p = sysMsg;
    while( ( *p > 31 ) || ( *p == 9 ) )
      ++p;
    do { *p-- = 0; } while( ( p >= sysMsg ) &&
                            ( ( *p == '.' ) || ( *p < 33 ) ) );

    // Display the message
    to_out( TEXT("\n  WARNING: %s failed with error %d (%s)"), msg, eNum, sysMsg );
  }

};
#undef to_out
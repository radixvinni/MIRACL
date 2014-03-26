#include <iostream>
#include <string.h>
#include <dlfcn.h>

int main() {
    using std::cout;
    using std::cerr;

    cout << "C++ dlopen demo\n\n";

    // open the library
    cout << "Opening libschoof2.so...\n";
    void* handle = dlopen("./libschoof2.so", RTLD_LAZY);
    
    if (!handle) {
        cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
    }
    
    // load the symbol
    cout << "Loading symbol shoof2_main...\n";
    typedef int (*main_t)(int,char**);

    // reset errors
    dlerror();
    main_t _main = (main_t) dlsym(handle, "schoof2_main");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol 'schoof2_main': " << dlsym_error <<
            '\n';
        dlclose(handle);
        return 1;
    }
    
    // use it to do the calculation
    cout << "Calling main...\n";

                            char** argv=new char*[9];
                            for(int i=0;i<9;i++)argv[i]=new char[32];
                            strcpy(argv[0],"./shoof2.exe");
                            strcpy(argv[1],"1");
                            strcpy(argv[2],"1");
                            strcpy(argv[3],"5");
                            strcpy(argv[4],"2");
                            strcpy(argv[5],"0");
                            strcpy(argv[6],"0");
                            strcpy(argv[7],"-o");
                            strcpy(argv[8],"curveorder.log");
                            _main(9,(char**)argv);
                            for(int i=0;i<9;i++)delete[] argv[i];
                            delete[] argv;

    
    // close the library
    cout << "Closing library...\n";
    dlclose(handle);
}

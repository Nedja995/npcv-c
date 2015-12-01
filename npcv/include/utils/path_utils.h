#ifndef __NP_PATH_UTILS_H__
#define __NP_PATH_UTILS_H__

namespace nputils {



	void path_to_linux(char *winPath);
	void path_to_windows(char *unixPath);
	char *path_to_linux_alloc(const char *winPath);
	char *path_to_windows_alloc(const char *unixPath);



}



#endif
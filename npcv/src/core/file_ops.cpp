#include "../../include/core/file_ops.h"

#include <fstream>

namespace nputils
{
	bool file_write(const char * filepath, const char * text)
	{
		FILE *fp;
		fp = fopen(filepath, "wb");
		fwrite(text, sizeof(char), strlen(text), fp);

		return true;
	}

}
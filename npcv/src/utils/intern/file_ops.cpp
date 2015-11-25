#include "../file_ops.h"

#include <fstream>
#include "../../core/npstdlib/string.h"

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

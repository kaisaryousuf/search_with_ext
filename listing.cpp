#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "listing.h"



using namespace std;

void listdir(const char *name, int level)
{
	int count = 0;
	char *toSearch[] = { ".psd", ".bat" };
	int ts;
	DIR *dir;
	struct dirent *entry;
	if (!(dir = opendir(name)))
		return;
	if (!(entry = readdir(dir)))
		return;

	do {
		if (entry->d_type == DT_DIR) {
			char path[1024];
			int len = snprintf(path, sizeof(path) - 1, "%s/%s", name, entry->d_name);
			path[len] = 0;
			if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
				continue;
			listdir(path, level + 1);
		}
		else {
			const char *ext = strrchr(entry->d_name, '.');
			if ((!ext) || (ext == entry->d_name))
				;
			else {
				for (ts = 0; ts < 2; ts++){
					
				if (strcmp(ext, toSearch[ts]) == 0) { //search array

					////\\\\\ Do whatever \\\\\\////

					printf("%*s- %s\n", level * 2, "", entry->d_name);  
					
					
				}
					count++;
				}
			}

		}
	} while (entry = readdir(dir));
	closedir(dir);

}

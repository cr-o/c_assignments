#include <sys/types.h>
#include <sys/param.h> /* for NGROUPS_MAX */
#include <limits.h>
#include <unistd.h>
#include <grp.h> 
#include <stdio.h>
int main(void){
	struct group *ptrname;
	int num_groups;
	gid_t grouplist[NGROUPS_MAX];
	gid_t *gi;
	gid_t GID;
	num_groups=getgroups(NGROUPS_MAX, grouplist);
	printf("There are %d supplementary groups\n", num_groups);
	for (int i=0; i<num_groups; i++){
		GID = grouplist[i];
		ptrname = getgrgid(GID);
		printf("group %d\t name is %s\n", grouplist[i], ptrname->gr_name);
	}
	return 0; 
}
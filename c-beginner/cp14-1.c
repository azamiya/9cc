// http://www.isl.ne.jp/pcsp/beginC/C_Language_14.html

#include <stdio.h>

struct SALARY {
	int april;
	int may;
	int june;
};

struct EMPLOYEE {
	int id;
	char *name;
	char *depertment;
	char *role;
	struct SALARY salary;
};


int main() {
	printf("社員番号\t   氏名\t部署\t役職\t月給\n");
	
	struct EMPLOYEE employees[] = {
		{1, "Ada", "総務", "部長", {435000,440000,437500}},
		{2, "Ada2", "営業", "部長", {450000,470000,460000}},
		{3, "Ada3", "広報", "ヒラ", {398000,425000,411500}}
	};

	int i = 0;
	int l = sizeof(employees)/sizeof(struct EMPLOYEE);
	for(i=0;i<l;i++){
		printf(
			"%7d%15s%8s%10s%8d%8d%8d\n",
			employees[i].id,
			employees[i].name,
			employees[i].depertment,
			employees[i].role,
			employees[i].salary.april,
			employees[i].salary.may,
			employees[i].salary.june);
	};
	printf("--------------\n");
	for(i=0;i<l;i++){
		printf(
			"%7d%15s%8s%10s%8d%8d%8d\n",
			(employees+i)->id,
			(employees+i)->name,
			(employees+i)->depertment,
			(employees+i)->role,
			(employees+i)->salary.april,
			(employees+i)->salary.may,
			(employees+i)->salary.june);
	};
	printf("--------------\n");
	for(i=0;i<l;i++){
		printf(
			"%7d%15s%8s%10s%8d%8d%8d\n",
			(*(employees+i)).id,
			(*(employees+i)).name,
			(*(employees+i)).depertment,
			(*(employees+i)).role,
			(*(employees+i)).salary.april,
			(*(employees+i)).salary.may,
			(*(employees+i)).salary.june);
	};
};
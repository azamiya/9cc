// http://www9.plala.or.jp/sgwr-t/c/sec15.html#s15-1

# include <stdio.h>

struct seiseki {
	int no;
	char *name;
	double average;
};

int main() {
	int i;
	struct seiseki student1 = {5, "ADA", 83.5};
	struct seiseki student2[20] = {
		{1, "hoge", 87.6},
		{2, "fuga", 98.3},
		{3, "piyo", 90.2}
	};
	printf("%d %s %5.1f\n", student1.no, student1.name, student1.average);

	for(i=0;i<3;i++){
		printf("%d %s %5.1f\n", student2[i].no, student2[i].name, student2[i].average);
	};
};
#include<unistd.h>
int main(void){
	for(int i = 0 ; i < 5; i++)
	{
		fork();
	}
	sleep(5);
	return 0;
}

/*for N = 3 the tree would look like
		bash---ex2---ex2---ex2---ex2
             ¦     ¦     +-ex2
             ¦     +-ex2---ex2
             ¦     +-ex2
             +-pstree

explaination: 1st fork() makes ex2 fork into ex2 and p1.
2nd fork() makes ex2 forks into ex2 and p2, p1 into p1 and p3
3rd fork() makes ex2 forks into ex2 and p4, p2 into p2 and p5, p1 into p1 and p6, p3 into p3 and p7
put them all together into the hierarchy, we achive the above result.

for N = 5 the tree would look like
        +---------------bash---ex2---ex2---ex2---ex2---ex2---ex2
        ¦                    ¦     ¦     ¦     ¦     +-ex2
        ¦                    ¦     ¦     ¦     +-ex2---ex2
        ¦                    ¦     ¦     ¦     +-ex2
        ¦                    ¦     ¦     +-ex2---ex2---ex2
        ¦                    ¦     ¦     ¦     +-ex2
        ¦                    ¦     ¦     +-ex2---ex2
        ¦                    ¦     ¦     +-ex2
        ¦                    ¦     +-ex2---ex2---ex2---ex2
        ¦                    ¦     ¦     ¦     +-ex2
        ¦                    ¦     ¦     +-ex2---ex2
        ¦                    ¦     ¦     +-ex2
        ¦                    ¦     +-ex2---ex2---ex2
        ¦                    ¦     ¦     +-ex2
        ¦                    ¦     +-ex2---ex2
        ¦                    ¦     +-ex2
        ¦                    +-pstree

#define SIZE 4096


typedef struct buff_kb* buff;

struct buff_kb{
    int pos;
    int len;
    char buffer[SIZE];
};

int getPos();
int newPos(int newPos);
char * getAddress();
char getCharAt(int pos);
void deleteBuffAt(int pos);

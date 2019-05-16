#include <iostream>

using std::cout;
using std::endl;

class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str==nullptr)
            return;
        int CountOfBlank = 0;
        int OriginLen = 0;
        for(int i=0;str[i]!='\0';++i){
            OriginLen++;
            if(str[i]==' ')
                ++CountOfBlank;
        }
        int newLen = OriginLen + 2*CountOfBlank;
        if(newLen+1>length)
            return;
        char* pStr1 = str+OriginLen; //用来保存\0
        char* pStr2 = str+newLen; //新的string
        while(pStr1<pStr2){
            if(*pStr1==' ')
            {
                *pStr2--='0';
                *pStr2--='2';
                *pStr2--='%';
            }
            else{
                *pStr2-- = *pStr1;
            }
            --pStr1;
        }
				for(int i=0;pStr2[i]!='\0';++i){
						cout << pStr2[i];
			}
			cout << endl;
	}

};

const int length = 1024;

int  main()
{
	Solution s;
  char* ss="hello world";
	s.replaceSpace(ss,length);
	return 0;
}

#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    void getNext(int* next,const string& s){
        int j=-1;
        next[0]=j;
        for (int i = 1; i < s.size(); i++)//i从1开始
        {
            /* code */
            while (j>=0&&s[i]!=s[j+1])//前后缀不同
            {
                /* code */
                j=next[j];//向前回溯
            }
            if (s[i]==s[j+1])//找到相同前后缀
            {
                /* code */

            }
            next[i]=j;//将j（前缀长度）赋值给next[i];
        } 
    }

    int strStr(string haystack, string needle) {
        if (needle.size()==0)
        {
            /* code */
            return 0;
        }
        int next[needle.size()];
        
        getNext(next,needle);
        int j=-1;
        for (int i = 0; i < haystack.size(); i++)
        {
            /* code */
            while (j>=0&&haystack[i]!=needle[j+1])//不匹配
            {
                /* code */
                j=next[j];
            }
            if (haystack[i]==needle[j+1])//匹配，j和i同时向后移动
            {
                /* code */
                j++;//i的增加在for循环里；
            }
            if (j==(needle.size()-1))//文本串s里出现模式串t
            {
                /* code */
                return (i-needle.size()+1);
            }
            
        }
        return -1;
        
    }

};

class solution{
public:
    void getNext(int* next,const string& s){
        int j=0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++)
        {
            /* code */
            while (j>0&&s[i]!=s[j])
            {
                /* code */
                j=next[j-1];
            }

            if (s[i]==s[j])
            {
                /* code */
                j++;
            }
            
            next[i]=j;
        }
        
    }
    int strStr(string haystack, string needle){
        if (needle.size()==0)
        {
            /* code */
            return 0;
        }
        int next[needle.size()];
        getNext(next,needle);
        int j=0;
        for (int i = 0; i < haystack.size(); i++)
        {
            /* code */
            while (j>0&&haystack[i]!=needle[j])
            {
                /* code */
                j=next[j-1];
            }
            if (haystack[i]==needle[j])
            {
                /* code */
                j++;
            }
            if (j==needle.size())
            {
                /* code */
                return (i-needle.size()+1);
            }
            
        }
        return -1; 
    }
};
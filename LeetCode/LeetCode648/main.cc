#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using std::set;
using std::string;
using std::vector;
using std::cout;
using std::endl;

//单词替换
//
class Solution{
  public:
    string replaceWords(vector<string>& dict,string sentence){
      string s;
      set<int> rootSize; //词根长度集合
      vector<string> words; //存储sentence以空格分割结果
      //第一步，以空格进行切割
      spilt(words,sentence,' ');
      //第二步，将词根转换set容器，并计算词根长度
      set<string> dictSet(dict.begin(),dict.end());
      for(auto& word : dict){
        rootSize.insert(word.size());
      }
      //第三步，开始搜索各个单词是否在词根
      for(auto& word : words){
        bool flag=false;
        string str; //已找到的词根
        //词根长度必须是长度集合中的元素，并且不大于word自身的长度
        for(auto it = rootSize.begin(); it != rootSize.end() && *it < word.size(); ++it){
          //获取word前*it个字符
          str = word.substr(0,*it);
          if(dictSet.find(str) != dictSet.end()){
            flag=true;
            break;
          }
        }
        if(flag){
          //如果是词根直接放入s
          s += str + " ";
        }
        else{
          //否则将单词直接放入
          s += word + " ";
        }
      }
      //去掉多余空格
      if(s.size() > 0){
        s.resize(s.size()-1);
      }
      return s;
    }
    void spilt(vector<string>& words,string& sentence,char ch){
      int size = sentence.size();
      int index = 0;
      while(index < size){
        string str;
        while(index < size && sentence[index] != ch){
          str += sentence[index++];
        }
        words.push_back(str);
        index += 1;
      }
    }
};

int main()
{
  Solution s;
  vector<string> vs{"cat","bat","rat"};
  string sentence = "the cattle was rattled by the battery";
  cout << s.replaceWords(vs,sentence) << endl;
  return 0;
}

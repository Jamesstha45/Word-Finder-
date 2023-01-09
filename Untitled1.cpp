#include<iostream>
#include<bits/stdc++.h>
#include<Windows.h>
#include<strings.h>
using namespace std;
#define char_int(c) ((int)c - (int)'a')
#define SIZE (26)
#define M 10
struct TrieNode
{
TrieNode *Child[SIZE];
bool leaf;
};
TrieNode *getNode()
{
    TrieNode * newNode = new TrieNode;
    newNode->leaf = false;
    for (int i =0 ; i< SIZE ; i++)
        newNode->Child[i] = NULL;
    return newNode;
}
void insert(TrieNode *root, string Key)
{
    int n = Key.length();
    TrieNode * pChild = root;
   for (int i=0; i<n; i++)
    {
        int index = char_int(Key[i]);

        if (pChild->Child[index] == NULL)
            pChild->Child[index] = getNode();
        pChild = pChild->Child[index];
    }
  pChild->leaf = true;
}
bool isSafe(int i, bool visited[M],int n)
{
   return (i >=0 && i < n && !visited[i]);
}
void searchWord(TrieNode *root, char boggle[M], int i,bool visited[M], string str,int n)
{
    if (root->leaf == true){
    	string dword;
    	fstream outfile;
    outfile.open("results.txt", std::ios::app);
	outfile<<str<<endl;}

    if (isSafe(i, visited,n))
    {  visited[i] = true;
        for (int K =0; K < SIZE; K++)
        {
            if (root->Child[K] != NULL)
            {

                char ch = (char)K + (char)'a' ;
                for(int t=0;t<n;t++){
                if (isSafe(t,visited,n) && boggle[t]== ch)
                    searchWord(root->Child[K],boggle,t,visited,str+ch,n);
            }
        }
    }
	visited[i] = false;
} }
void findWords(char boggle[M], TrieNode *root,int n)
{
    bool visited[n];
    memset(visited,false,sizeof(visited));
    TrieNode *pChild = root ;
    string str = "";
    for (int i = 0 ; i < n; i++)
    {
            if (pChild->Child[char_int(boggle[i])] )
            {
                str = str+boggle[i];
                searchWord(pChild->Child[char_int(boggle[i])],
                           boggle, i, visited, str,n);
                str = "";
            }
        }
    }
int main()
{
POINT p[10];
string hello;
	string dame[200];
	int b =0;
	int k=1;
cin>>hello;
 	int i=0,j=0,m=0;
 	string name[200];
 	int found=6796;
 	int q=hello.length();
 	switch(q){
 		case 4:
 			p[0].x=681;
 			p[0].y=520;
 			
 				p[1].x=620;
 			p[1].y=582;
 			
 				p[2].x=676;
 			p[2].y=644;
 			
 				p[3].x=746;
 			p[3].y=576;
 			break;
 		case 5:
		 	p[0].x=683;
 			p[0].y=508;
			 
			 	p[1].x=624;
 			p[1].y=551;
			 
			 	p[2].x=645;
 			p[2].y=617;
			 
			 	p[3].x=714;
 			p[3].y=617;
			 
			 	p[4].x=740;
 			p[4].y=550;
 			break;
			 	
 		case 6:
		 	p[0].x=686;
 			p[0].y=520;
			 
			 	p[1].x=627;
 			p[1].y=556;
			 
			 	p[2].x=626;
 			p[2].y=622;
			 
			 	p[3].x=676;
 			p[3].y=650;
			 
			 	p[4].x=742;
 			p[4].y=609;
			 
			 	p[5].x=742;
 			p[5].y=552;	
 			break;
 			case 7:
 					p[0].x=681;
 			p[0].y=508;
 			
 				p[1].x=626;
 			p[1].y=542;
 			
 				p[2].x=615;
 			p[2].y=601;
 			
 				p[3].x=651;
 			p[3].y=644;
 			
 				p[4].x=710;
 			p[4].y=644;
 			
 				p[5].x=747;
 			p[5].y=598;
 			
 				p[6].x=737;
 			p[6].y=539;
 			break;
 			case 3:
 					p[0].x=681;
 			p[0].y=537;
 			
 				p[1].x=627;
 			p[1].y=607;
 			
 				p[2].x=736;
 			p[2].y=619;
 			
 			break;
	 }
 /*	while(true){
 		if(GetAsyncKeyState(VK_NUMPAD1)){

 			GetCursorPos(&p[i]);
 			Sleep(200);
 			i++;
 				cout<<i;
		 }
	 if(GetAsyncKeyState(VK_NUMPAD0)){
		 	break;
		 }}*/
    TrieNode *root = getNode();
    fstream file;
    string dword, filename,pname;
    filename = "alpha.txt";
    file.open(filename.c_str());
    while (file >> dword)
    {   insert(root,dword); }
    file.close();
    char boggle[q];
    for(int i=0;i<hello.length();i++){
    	 boggle[i] = hello[i];
	}
    int n=sizeof(boggle)/sizeof(boggle[0]);
    for(int i=0;i<n;i++){
    	pname=pname+boggle[i];
	}
	findWords(boggle, root,n);
   fstream gfile;
  string filename2,gord;
  filename2="results.txt";
  gfile.open(filename2.c_str());
  while(gfile>>gord){
  	dame[b]=gord;
  	b++;
  	k++;}	
	string tempu;
	for(int i=0;i<k;i++){
		for(int j=i+1;j<k;j++){
			if(dame[i].length()<dame[j].length()){
				tempu=dame[j];
				dame[j]=dame[i];
				dame[i]=tempu;
			}
		}
	}
	fstream pfile;
	pfile.open("results.txt", ios::out);
	for(int i=0;i<k;i++)
	pfile<<dame[i]<<endl;	
	 label:	 	
    fstream efile;
  string word,filename_;
  filename_="results.txt";
  efile.open(filename_.c_str());
  while(efile>>word){
  	int t=0;
  	string sname=pname;
  	name[m]=word;
  	for(int q=0;q<m;q++){
  		if(name[q]==word){
  			goto pappu;
		  }
	  }
	  m++;
  	cout<<word<<endl;
    for(i=0;i<word.length();i++){
		 		for(int j=0;j<sname.length();j++){
		if(word[i]==sname[j]){
			SetCursorPos(p[j].x, p[j].y);
			Sleep(100);
			if(t==0){
            mouse_event(MOUSEEVENTF_LEFTDOWN, p[i].x,p[i].y, 0, 0);
			Sleep(100);
            t=1;}
            sname[j]='@';
		break;
			}
	}
	}
	mouse_event(MOUSEEVENTF_LEFTUP,p[j].x,p[j].y,0,0);
	pappu:
 		if(GetAsyncKeyState(VK_NUMPAD3)){
 		break;
		 }
    }
    while(true){
    if(GetAsyncKeyState(VK_NUMPAD2)){
    	goto label;
	}
	if(GetAsyncKeyState(VK_NUMPAD0)){
		break;
	}

}
   ofstream outfile;
  outfile.open("results.txt",std::ios_base::trunc);
  outfile.close();
  return 0;}

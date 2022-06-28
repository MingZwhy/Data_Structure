#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
//���ݱ��ʽ�γɵĶ���������Ҷ�ӽڵ㶼�����ֵ��ص�
//�������沨�����ʽ�����ʽ�ĺ���ʱ�����������������ʽ�����沨�����ʽ����Ӧͬһ�ö�������
//�������ʽ��Ӧ����������������沨�����ʽ��Ӧ�����ĺ������
//���Դ�ʱ�����и����ĺ�������������������ᵽ��Ҷ�����ԣ�����������������ַ����飬��
//ÿ�����ֺ�����������ַ�N����ζ��Ǹ����ֵ������ӽڵ㶼Ϊ�գ����ø�������������
//�Ը��ڵ�--���ӽڵ�--���ӽڵ��˳��Ϳ��Խ����ö���������һ˳��պ��Ǻ����������˳��˵������������պ����෴�� 
//����������ö��������Եõ��������ʽ������֮������û�����ţ� 
//ʵ����û�����ŵ�ԭ�����������ֻ�ɺ���������޷�ȷ��Ψһһ�Ŷ������ģ�����֪�����ֱ����ſ�Ψһȷ��һ������ 

typedef struct TreeNode{
	char elem;
	struct TreeNode *left,*right;
}Bitree, *tree;

void transform(char *s,char *t){
	int len=strlen(s);
	int i,j;
	for(i=0,j=0;i<len;i++,j++){
		if(isdigit(s[i])){
			t[j++]='N';
			t[j++]='N';
			t[j]=s[i];
		}
		else if(s[i]==' '){
			j--;
		}
		else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
			t[j]=s[i];
		}
		else{
			printf("error!");
		}
	}
	t[j]='\0';
}

void self_getline(char *s){
	int i=0;
	char c;
	while((c=getchar())!='\n' && i<100-2){
		s[i++]=c;
	}
	s[i]='\0';
}

void backinittree(tree *T,char *t,int *index){
	if(t[*index]=='N'){
		*T=NULL;
		(*index)++;
	}
	else{
		*T=(tree)malloc(sizeof(Bitree)*1);
		(*T)->elem=t[*index];
		(*index)++;
		backinittree(&((*T)->right),t,index);
		backinittree(&((*T)->left),t,index);
	}
}

void prereadtree(tree T,char *result,int *index){
	if(T==NULL){
		;
	}
	else{
		prereadtree(T->left,result,index);
		result[*index]=T->elem;
		(*index)++;
		prereadtree(T->right,result,index);
	}
}

void reverse(char *t){
	int len=strlen(t);
	for(int i=0,j=len-1;i<j;i++,j--){
		char temp=t[i];
		t[i]=t[j];
		t[j]=temp;
	}
}

int main(){
	char *s,*t;
	s=(char *)malloc(sizeof(char)*100);
	t=(char *)malloc(sizeof(char)*300);
	printf("�������沨�����ʽ��");
	self_getline(s);
	printf("ԭ���ʽΪ��%s\n",s);
	transform(s,t);
	printf("%s\n",t);
	reverse(t);
	printf("%s\n",t);
	
	tree a=NULL;
	int index=0;
	backinittree(&a,t,&index);
	char *result;
	result=(char *)malloc(sizeof(char)*300);
	index=0;
	prereadtree(a,result,&index);
	result[index]='\0';
	printf("\nת����Ϊ��%s",result);
	return 0;
}

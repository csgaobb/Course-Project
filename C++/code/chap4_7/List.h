#define MAX 25
class Student{
	char name[MAX];
	char password[MAX];
	float English;
	float Math;
	float Physics;
	float Chemistry;
public:
	Student();				//Ĭ�Ϲ���һ���յļ�¼
	Student(char *nam,char *psw);		//����һ����������������ļ�¼
	Student(char *name,char *psw,float Eng,float Math,float phy,float chem); //���������ļ�¼
	~Student();
	float getEnglish();				//�õ�Ӣ��ɼ�
	float getMath();			//�õ���ѧ�ɼ�
	float getPhysics();			//�õ�����ɼ�
	float getChemistry();		//�õ���ѧ�ɼ�
	void changeName(char *newname);		//��������
	void changePassword(char *newpassword);    //��������
	void setEnglish(float Englishscore);	//  �趨/�޸�Ӣ��ɼ�
	void setMath(float Mathscore);			//  �趨/�޸���ѧ�ɼ�
	void setPhysics(float Physicscore);		//  �趨/�޸�����ɼ�
	void setChemistry(float Chemistryscore);		//  �趨/�޸Ļ�ѧ�ɼ�
	int enterPsw(char *input);			//�������룬�ɹ�ƥ�䷵��1�����򷵻�0
	void print();			//���������Ϣ�����ڵ���ʹ��
};

public class JLab0503 {
	public static void main(String args[]){
		System.out.println("�����������:");
		SuperClass sc0 = new SuperClass();
		System.out.println("\n ������һ���������: ");
		SubClass sc1 = new SubClass();
//		System.out.println("\n �����ڶ����������: ");
//		SubClass sc2 = new SubClass();
	}
}

class SuperClass{
	SuperClass(){
		System.out.println("����Ĺ��캯��");
	}
}

class SubClass extends SuperClass{
//	SubClass(){
//		System.out.println("����ĵ�һ�����캯��");
//	}
//	SubClass(int i){
//		System.out.println("����ĵڶ������캯��");
//	}
}


import java.lang.Number;

public class score{
	public static void main(String[] args){
		int b = Integer.valueOf(args[0]).intValue();
		int a = b / 10;
		switch(a){
			case 10: System.out.println("����");break;
			case 9: System.out.println("����");break;
			case 8: System.out.println("����");break;
			case 7: System.out.println("�е�");break;
			case 6: System.out.println("����");break;
			default: System.out.println("������");
		}	
	}
}
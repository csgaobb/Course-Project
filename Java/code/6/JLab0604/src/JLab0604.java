import java.util.Calendar;
public class JLab0604 {
	public static void main(String[] args) {
		final String dayNames[] = { "������", "����һ", "���ڶ�", "������", "������", "������","������" };
		Calendar   calendar   =   Calendar.getInstance();   
		int   month   =   calendar.get(Calendar.MONTH)+1;
		int   year    =   calendar.get(Calendar.YEAR);
		int   date 	  =   calendar.get(Calendar.DATE);
		int   dayOfWeek  = calendar.get(Calendar.DAY_OF_WEEK);
		System.out.print("������ ");
		System.out.print(year+" ��  ");
		System.out.print(month+" ��  ");
		System.out.print(date+" ��  ");
		System.out.print(dayNames[dayOfWeek-1]);
	}
}

import java.util.Arrays;

public class JLab0602 {
	public static void main(String[] args) {
		String[] animals = {"cat","fish","mouse"};
		int[] lengthOfString = new int[animals.length];  //����Ļ�ֱ����һ����Ա����������
		for (int j = 0; j < animals.length; j++){
			lengthOfString[j] = animals[j].length(); //string�����length������Ҫ������
		}
		Arrays.sort(lengthOfString);
		for(int i = lengthOfString.length-1 ; i >=0 ; i--){
			for (int j = 0; j < animals.length;j++){
				if (animals[j].length() == lengthOfString[i])
					System.out.print(animals[j].toUpperCase()+" ");
			}
		}
		System.out.println();
	}
}

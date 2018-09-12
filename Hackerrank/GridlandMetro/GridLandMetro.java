package main;

import java.util.*;
import java.math.BigInteger;

/**
 * Created by nxphi47 on 10/29/16.
 */
public class GridLandMetro {
	public static String makeRandomInput(){
		Random random = new Random();
		int n = 800000922;
		int m = 523123212;
		int k = 30;
		//System.out.printf("%d %d %d\n", n, m, k);
		StringBuilder stringBuilder = new StringBuilder(String.format("%d %d %d\n", n, m, k));
		for (int i = 0; i < k; i++){
			int r = random.nextInt(n) + 1;
			int left = random.nextInt(m) + 1;
			int right = random.nextInt(m - left) + left;
			//System.out.printf("%d %d %d\n",r, left, right);
			stringBuilder.append(String.format("%d %d %d\n", r,left, right));
		}
		return stringBuilder.toString();
	}

	public static class Vector {
		public int row;
		public int left;
		public int right;
		public Vector(int r,int left, int right){
			row = r;
			this.left = left;
			this.right = right;
		}
		public int getLength(){
			if (left > right){
				return -1;
			}
			return right - left + 1;
		}
	}

	public GridLandMetro() {
//		String randomInput = makeRandomInput();
		//System.out.printf("%s\n", randomInput);
		Scanner scanner = new Scanner(System.in);
//		Scanner scanner = new Scanner(randomInput);
		int rows = scanner.nextInt();
		int cols = scanner.nextInt();
		int trackTotal = scanner.nextInt();
		//ArrayList<LinkedList<Vector>> rowList = new ArrayList<>(rows + 1);
		ArrayList<Vector> tracks = new ArrayList<>(trackTotal);
		// input the tracks
		for (int i = 0; i < trackTotal; i++){
			int row = scanner.nextInt();
			int left = scanner.nextInt();
			int right = scanner.nextInt();
			tracks.add(new Vector(row, left, right));
		}
		// sort the tracks
//		System.out.printf("\nTracks created");
		Collections.sort(tracks, new Comparator<Vector>() {
			@Override
			public int compare(Vector o1, Vector o2) {
				if (o1.row > o2.row){
					return 1;
				}
				else if (o1.row < o2.row){
					return -1;
				}
				else{
					// same row, larger range go first
					int range1 = o1.getLength();
					int range2 = o2.getLength();
					if (range1 > range2){
						return -1;
					}
					else if (range1 < range2){
						return 1;
					}
					else {
						return 0;
					}
				}
			}
		});
//		System.out.printf("\nTracks sorted");
		// add track to rowList or merging
		BigInteger sum = new BigInteger(String.valueOf(rows));
		sum = sum.multiply(new BigInteger(String.valueOf(cols)));

//		System.out.printf("\nSum = %s", sum);
		int currentRow = 0;
		LinkedList<Vector> list = new LinkedList<>();
		int i = 0;
		for (i = 0; i < tracks.size(); i++){
			if (tracks.get(i).row != currentRow){
				// minus sum and clear list and add the first one
				if (list.size() != 0){
					for (Vector vector: list){
//						System.out.printf("\nvector: %d %d %d", vector.row, vector.left, vector.right);
						sum = sum.subtract(new BigInteger(String.valueOf(vector.getLength())));
					}
				}
				list.clear();
				currentRow = tracks.get(i).row;
				addVector(list, tracks.get(i));
			}
			else {
				addVector(list, tracks.get(i));
			}
		}
		// finish the last row
		if (list.size() != 0){
			for (Vector vector: list){
//				System.out.printf("\nvector: %d %d %d", vector.row, vector.left, vector.right);
				sum = sum.subtract(new BigInteger(String.valueOf(vector.getLength())));
			}
		}
		System.out.printf("%s", sum);
	}
	// need to be add the largest range first
	public static LinkedList<Vector> addVector(LinkedList<Vector> list, Vector vec){
		if (list.size() == 0){
			list.add(vec);
			return list;
		}
		for (int i = 0; i < list.size(); i++){
			if (vec.right < list.get(i).left - 1){
				// add previous
				list.add(i, vec);
				break;
			}
			else if (vec.left < list.get(i).right + 2){
				// merging
				if (vec.left >= list.get(i).left && vec.right <= list.get(i).right){
					break; // do nothing, previous obsorb
				}
				else {
					// left merge
					if (vec.left < list.get(i).left){
						list.get(i).left = vec.left;
					}
					// merge right
					if (vec.right > list.get(i).right){
						list.get(i).right = vec.right;
					}
					// merge with previous and after
					if (i - 1 >= 0 && list.get(i).left <= list.get(i - 1).right + 1){
						list.get(i-1).right = list.get(i).right;
						list.remove(i);
						i--;
					}
					//right side
					if (i + 1 < list.size() && list.get(i).right >= list.get(i + 1).left - 1 ){
						list.get(i).right = list.get(i + 1).right;
						list.remove(i + 1);
					}
					break;

				}
			}
			else if (i == list.size() - 1){
				// add after only if i = end
				list.addLast(vec);
			}
		}

		return list;
	}
}

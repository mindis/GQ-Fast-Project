package gqfast.global;


import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class MetaData {
	
	public static final int ENCODING_UA = 1;
	public static final int ENCODING_BCA = 2;
	public static final int ENCODING_BB = 3;
	public static final int ENCODING_HUFFMAN = 4;

	public static final int BYTES_1 = 1;
	public static final int BYTES_2 = 2;
	public static final int BYTES_4 = 4;
	public static final int BYTES_8 = 8;
	
	private List<MetaIndex> indexList;
	private List<MetaQuery> queryList;
	
	private int currentQueryID;
	
	public MetaData() {
		indexList = new ArrayList<MetaIndex>();
		queryList = new LinkedList<MetaQuery>();
		currentQueryID = 0;
	}
	
	public void setIndexList(List<MetaIndex> indexList)
	{
		this.indexList = indexList;
	}

	public int getCurrentQueryID() {
		return currentQueryID;
	}

	public void setCurrentQueryID(int currentQueryID) {
		this.currentQueryID = currentQueryID;
	}

	public List<MetaIndex> getIndexList() {
		return indexList;
	}

	public List<MetaQuery> getQueryList() {
		return queryList;
	}

	public int getMaxIndexID() {
		int max = 0;
		for (MetaIndex index : indexList) {
			if (max < index.getGQFastIndexID()) {
				max = index.getGQFastIndexID();
			}
		}
		return max;
	}
	
	public int getMaxColID() {
		int max = 0;
		for (MetaIndex index : indexList) {
			if (max < index.getMaxColumnID()) {
				max = index.getMaxColumnID();
			}
		}
		return max;
	}
}

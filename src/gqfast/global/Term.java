package gqfast.global;

public class Term {
	private String variable;
	private String column;
	private String col_constant;
	
	public Term(String col_con) {
		this.variable = null;
		this.column = null;
		this.col_constant = col_con;
	}
	
	public Term(String var, String col) {
		this.variable = var;
		this.column = col;
		this.col_constant = null;
	}
	
	public String get_variable() {
		return this.variable;
	}
	
	public String get_column() {
		return this.column;
	}
	
	public String get_constant() {
		return this.col_constant;
	}
	
	public void print() {
		if (this.col_constant == null) {
			if (this.column != "")
				System.out.print(this.variable+"."+this.column);
			else
				System.out.print(this.variable);
		}else
			System.out.print(this.col_constant);
	}
}
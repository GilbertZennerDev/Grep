public class Tester
{
	public static void main(String[] args)
	{
		Grep g = new Grep();
		String target;
//		String filename;

		target = "1";
		if (args.length > 0) target = args[0];
		g.doGrep(target, "stdin", false);
		g.doGrep(target, "txt", false);
	}
}

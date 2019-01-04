/**
 * GetNthLastNode
 */
public class GetNthLastNode {

	public static void main(String[] args) {
		LinkedList list = new LinkedList();
		list.insertTail(0);
		list.insertTail(2);
		list.insertTail(2);
		list.insertTail(2);
		list.insertTail(2);
		list.insertTail(8);
		list.insertTail(8);
		list.printList();
		System.out.println(list.getNthLastNode(3).data);
		System.out.println(list.getNthLastNode(2).data);
	}
}

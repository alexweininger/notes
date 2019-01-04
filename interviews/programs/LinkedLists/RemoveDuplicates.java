/**
 * RemoveDuplicates
 */
public class RemoveDuplicates {

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
		LinkedList.removeDuplicates(list.head);
		list.printList();
	}
}

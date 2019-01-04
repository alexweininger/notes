import java.util.ArrayList;
import java.util.Hashtable;

/**
 * LinkedList
 */
public class LinkedList {
	public Node head;

	public static class Node {
		int data;
		Node next;

		public Node(int d) {
			this.data = d;
			this.next = null;
		}
	}

	LinkedList() {
		this.head = null;
	}

	void insertTail(int d) { // O(N)
		Node n = this.head;
		if (head == null) {
			head = new Node(d);
			return;
		}
		while (null != n.next)
			n = n.next;
		n.next = new Node(d);
	}

	void insertHead(int d) {
		Node n = Node(d);
		n.next = this.head;
		this.head = n;
	}

	void printList() {
		Node n = head;
		while (null != n) {
			System.out.print(n.data + " ");
			n = n.next;
		}
		System.out.println();
	}

	// ctci 2.1 remove duplicates from a linked list
	public static void removeDuplicates(Node list) {
		Hashtable nums = new Hashtable();

		Node n = list;
		LinkedList.Node prev = null;
		while (n != null) {
			if (nums.containsKey(n.data)) {
				if (prev == null) {
					list = n.next;
				} else {
					prev.next = n.next;
				}
			} else {
				nums.put(n.data, true);
				prev = n;
			}
			n = n.next;
		}
	}

	// ctci 2.2 return nth to last element from a linked list
	public  Node getNthLastNode(int n) {
		Node fast = head;
		Node slow = head;

		int i = 0;
		while (i < n) {
			if (fast == null) {
				return null;
			}
			fast = fast.next;
			i++;
		}
		while (fast != null) {
			fast = fast.next;
			slow = slow.next;
		}
		return slow;
	}

	public void deleteNode(Node node) {
		Node beforeDelete = this.head;
		while (null != beforeDelete && beforeDelete->next != node) {
			beforeDelete = beforeDelete.next;
		}
		Node toDelete = node.next;
		beforeDelete.next = toDelete.next;
	}

	public Node circularLinkedList(Node head) {
		ArrayList<Node> nodes = new ArrayList<>();

		Node n = head;
		while (null != n && !nodes.contains(n)) {
			nodes.add(n);
			n = n.next;
		}
		return n;
	}
}

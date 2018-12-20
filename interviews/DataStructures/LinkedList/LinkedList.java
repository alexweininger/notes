/**
 * LinkedList
 */
public class LinkedList {
	Node head;

	static class Node {
		int data;
		LinkedList next;

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
		while (null != n.next)
			n = n.next;
		n.next = new Node(d);
	}

	void insertHead(int d) {
		Node n = Node(d);
		n.next = this.head;
		this.head = n;
	}
}

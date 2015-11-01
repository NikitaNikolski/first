(function() {
  function DoublyLinkedList() {
    this._head = null;
    this._tail = null;
    this.count = 0;
  }

  function Node(data) {
    this.next = null;
    this.prev = null;
    this.data = data;
  }

  DoublyLinkedList.prototype.head = function() {
    if (this._head) {
      return this._head.data;
    }

    return null;
  }

  DoublyLinkedList.prototype.tail = function() {
    if (this._tail) {
      return this._tail.data;
    }

    return null;
  }

  DoublyLinkedList.prototype.append = function(data) {
    var node = new Node(data);

    if (this.count === 0) {
        this._head = node;
        this._tail = node;
    } else {
        this._tail.next = node;
        node.prev = this._tail;
        this._tail = node;
    }

    this.count++;
    return this;
  }

  DoublyLinkedList.prototype.at = function(index) {
    if (index > -1 && index < this.count) {
      var current = this._head,
          i = 0;

      if (index === 0) {
        return this._head.data;
      }
      else if (index === this.count - 1) {
        return this._tail.data;
      }
      else {
        while (i++ < index) {
          current = current.next;
        }
        return current.data;
      }
    }
    else return null;
  }

  DoublyLinkedList.prototype.insertAt = function(index, data) {
    var node = new Node(data);

    if (index > 0 && index < this.count) {
      var current = this._head,
          i = 0;

      while (i++ < index) {
        current = current.next;
      }

      current.prev.next = node;
      node.prev = current.prev;
      node.next = current;
      current.prev = node;
    } else if (index <= 0 && this._head) {
      node.next = this._head;
      this._head.prev = node;
      this._head = node;
    } else if (index >= this.count || (index <= 0 && !this._head)) {
      this.append(data);
    }

    this.count++;
    return this;
  }

  DoublyLinkedList.prototype.deleteAt = function(index) {
    if (index == this.count - 1) {
      this._tail = this._tail.prev;
      this._tail.next = null;
      this.count--;
    } else if (index == 0 && this._head) {
      this._head = this._head.next;
      this._head.prev = null;
      this.count--;
    } else if (index > 0 && index < this.count) {
      var current = this._head,
          i = 0;

      while (i++ < index) {
        current = current.next;
      }

      current.prev.next = current.next;
      current.next.prev = current.prev;
      this.count--;
    }

    return this;
  }

  DoublyLinkedList.prototype.reverse = function() {
    var node = new Node(),
        nodeHead = this._head,
        nodeTail = this._tail,
        i = 0;

    while (i < Math.floor(this.count / 2)) {
      node.data = nodeTail.data;
      nodeTail.data = nodeHead.data;
      nodeHead.data = node.data;
      nodeHead = nodeHead.next;
      nodeTail = nodeTail.prev;
      i++;
    }

    return this;
  }

  DoublyLinkedList.prototype.each = function(fn) {
    var i = 0,
        current = this._head;

    while (i++ < this.count) {
      fn(current);
      current = current.next;
    }

    return this;
  }

  DoublyLinkedList.prototype.indexOf = function(data) {
    var i = 0,
        current = this._head;

    while (i < this.count) {
      if (current.data == data) {
        return i;
      }

      i++;
      current = current.next;
    }

    return -1;
  }
})();

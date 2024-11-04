package IntegerSet;

public class IntegerSet {
    private int n = 100;
    private boolean[] arr = new boolean[10];

    public IntegerSet() {
        int i;

        for (i = 0; i < n; i++) {
            arr[i] = false;
        }
    }

    public IntegerSet union(IntegerSet a, IntegerSet b) {
        int i;
        IntegerSet c = new IntegerSet();

        for (i = 0; i < n; i++) {
            if (a.arr[i] || b.arr[i]) {
                c.arr[i] = true;
            } else {
                c.arr[i] = false;
            }
        }

        return c;
    }

    public IntegerSet intersection(IntegerSet a, IntegerSet b) {
        int i;
        IntegerSet c = new IntegerSet();

        for (i = 0; i < n; i++) {
            if (!a.arr[i] || !b.arr[i]) {
                c.arr[i] = false;
            } else {
                c.arr[i] = true;
            }
        }

        return c;
    }

    public void insertElement(int k) {
        if (k < n && k >= 0) {
            arr[k] = true;
        }
    }

    public void deleteElement(int m) {
        if (m < n && m >= 0) {
            arr[m] = false;
        }
    }

    public String toSetString() {
        int i;
        String stringSet = "";

        for (i = 0; i < n; i++) {
            if (arr[i]) {
                stringSet += arr[i];
            }
        }

        if (stringSet == "") {
            stringSet = "- -";
        }

        return stringSet;
    }

    public boolean isEqualTo(IntegerSet b) {
        int i;

        for (i = 0; i < n; i++) {
            if (arr[i] != b.arr[i]) {
                return false;
            }
        }

        return true;
    }
}

class DemoIntegerSet {
    public static void main(String[] args) {
        IntegerSet set = new IntegerSet();
    }
}

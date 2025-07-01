class Triangle{
    Syncronized void drawTriangle(int size){
        for(int i=1;i<size;i++){
            System.out.println("*".repeat(i));
        }
    }

    Syncronized void drawSquare(int size){
        for (int i=1;i<=size;i++){
            System.out.println("*".repeat(size));
        }
    }
}

class sync{
    public static void main(String[]args){
    Triangle t = new Triangle();
    Thread t1 = new Thread(() -> t.drawTriangle(5));
    Thread t2 = new Thread(() -> t.drawSquare(5));
    }
}
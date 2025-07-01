class myThread extends Thread {
    public void run(){
        System.out.println("current running thread:"+Thread.currentThread().getName());
            }
}

class myThread2 implements Runnable {
    public void run(){
        System.out.println("current Running Thread:"+Thread.currentThread().getName());
    }
}

public class prac{
    public static void main(String[] args){
        myThread t1 = new myThread();
        Thread t2 = new Thread(new myThread2());
        t1.start();
        t2.start();
    }
}
package hello.core.springbasic.singleton;

public class StatefulService {


    private int price; // state maintain field

    public void order(String name, int price) {
        System.out.println("name = " + name + " price = " + price);
        this.price = price; // problem!
    }

    public int getPrice() {
        return price;
    }
}

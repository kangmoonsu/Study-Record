package hello.core.springbasic.singleton;

public class SingletonService {

    // 1. Create only one object in the static area.
    private static final SingletonService instance = new SingletonService();

    // 2. Open it to the public and allow object access only through this static method
    // when an instance is needed.
    public static SingletonService getInstance() {
        return instance;
    }

    // 3. Declare the constructor as private to prevent object creation
    // from outside using the 'new' keyword.
    private SingletonService() {}

    public void logic() {
        System.out.println("Singleton object logic called");
    }
}

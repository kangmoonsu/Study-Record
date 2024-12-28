package hello.itemservice.domain.item;

public enum ItemType {
    BOOK("Book"), FOOD("Food"), ETC("Etc");

    private final String description;

    ItemType(String description) {
        this.description = description;
    }

    public String getDescription() {
        return description;
    }
}


package hello.itemservice.domain.item;

import lombok.Data;

import java.util.List;

@Data
public class Item {
    private Long id;
    private String itemName;
    private Integer price;
    private Integer quantity;
    private Boolean open; // Sale status
    private List<String> regions; // Registered regions
    private ItemType itemType; // Product type
    private String deliveryCode; // Delivery method

    public Item() {
    }

    public Item(String itemName, Integer price, Integer quantity) {
        this.itemName = itemName;
        this.price = price;
        this.quantity = quantity;
    }
}


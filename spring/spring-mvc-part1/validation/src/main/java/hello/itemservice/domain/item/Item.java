package hello.itemservice.domain.item;

import lombok.Data;
import org.hibernate.validator.constraints.Range;
import org.hibernate.validator.constraints.ScriptAssert;

import javax.validation.constraints.Max;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;

@Data
public class Item {

    @NotNull(groups = UpdateCheck.class) // Applied only during updates
    private Long id;

    @NotBlank(groups = {SaveCheck.class, UpdateCheck.class}) // Applied during both save and update
    private String itemName;

    @NotNull(groups = {SaveCheck.class, UpdateCheck.class}) // Applied during both save and update
    @Range(min = 1000, max = 1000000, groups = {SaveCheck.class, UpdateCheck.class}) // Price range validation
    private Integer price;

    @NotNull(groups = {SaveCheck.class, UpdateCheck.class}) // Applied during both save and update
    @Max(value = 9999, groups = SaveCheck.class) // Applied only during save
    private Integer quantity;

    public Item() {
    }

    public Item(String itemName, Integer price, Integer quantity) {
        this.itemName = itemName;
        this.price = price;
        this.quantity = quantity;
    }
}

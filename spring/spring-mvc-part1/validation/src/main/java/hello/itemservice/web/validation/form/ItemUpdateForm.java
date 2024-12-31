package hello.itemservice.web.validation.form;

import lombok.Data;
import org.hibernate.validator.constraints.Range;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;

@Data
public class ItemUpdateForm {

    @NotNull // ID is required for updates
    private Long id;

    @NotBlank // Item name cannot be blank
    private String itemName;

    @NotNull // Price cannot be null
    @Range(min = 1000, max = 1000000) // Price must be between 1,000 and 1,000,000
    private Integer price;

    // Quantity can be freely changed during updates
    private Integer quantity;
}

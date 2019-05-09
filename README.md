# Shopping-Cart
Making a GUI application for a technology store using the observer, builder, visitor, and mediator patterns.
The owner of the store wants to import products from a csv file, be able to add those items to a shopping cart, and check out the cart by pressing a button.

### What does it looks like?
### 1.
![image](https://user-images.githubusercontent.com/48369187/57421711-c5643a00-71da-11e9-8ada-3b2dbf0cb691.png)

This is a initial Mainwindow that shows up when the owner run the program.

### 2.
![image](https://user-images.githubusercontent.com/48369187/57421877-9e5a3800-71db-11e9-909d-5880c58d23ec.png)

#### Two csv files needed
1. One that contains items
2. The other that contains bundles

The data from csv files are imported after clicking "Load Database" Button. The application read the csv files and output the data to the screen. After importing data, load button is disabled.

### 3.
![image](https://user-images.githubusercontent.com/48369187/57421920-d5304e00-71db-11e9-9cb2-3481c89f50e9.png)

The owner may select products and bundles at the same time and press "Add to Cart" Button to add items to the cart. "Show Cart" button will open a new window (Shopping cart) and its name will change to "Hide Cart". When Hide Button is pressed, the shopping cart windown will be closed and its name will change to "Show Cart".

### 4.
![image](https://user-images.githubusercontent.com/48369187/57421983-24767e80-71dc-11e9-965a-8ebcf06ccdfe.png)

This is the shopping cart window that shows a list of added items and bundles. The owner may select products and bundles and delele them from the shopping cart by pressing "Delete" Button.

### 5.
![image](https://user-images.githubusercontent.com/48369187/57427755-6232d180-71f3-11e9-8a03-d7d3b9ff7d68.png)
If "Checkout" button is pressed, all other buttons are disabled but the hide button and total price of shopping cart will show up.

### What Design Patterns are used?
#### 1. Observer Pattern

![image](https://user-images.githubusercontent.com/48369187/57428126-f18cb480-71f4-11e9-82ec-70ef775f65dc.png)
(Source: Wikipedia)

The observer pattern was used for show button.

#### 2. Builder Pattern

![image](https://user-images.githubusercontent.com/48369187/57428173-2436ad00-71f5-11e9-92b5-352986fc188b.png)
(Source: Wikipedia)

There are one AbstractBuilder, two builder for Device and Bundle, and FileParser class in the project.

#### 3. Visitor Pattern

![image](https://user-images.githubusercontent.com/48369187/57428182-30226f00-71f5-11e9-87a9-3af18c2c75bc.png)
(Source: Wikipedia)

The visitor pattern was used for checkout button.

#### 4. Mediator Pattern

![image](https://user-images.githubusercontent.com/48369187/57428197-44ff0280-71f5-11e9-85c8-ff44e8b1e6b9.png)
(Source: Wikipedia)

The mediator pattern was used for add button.


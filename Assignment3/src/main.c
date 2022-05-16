/*
 * Bruno Feitais, 2022/05
 * Assignment 3 - Implementation of State Machines on Embedded Systems
 * 
 * Button 1 - Browses Up
 * Button 2 - Comprar produto selecionado
 * Button 3 - Browses Down
 * Button 4 - Devolver creditos
 * Button 5 - Adicionar 10  creditos
 * Button 6 - Adicionar 20  creditos
 * Button 7 - Adicionar 50  creditos
 * Button 8 - Adicionar 100 creditos
 * 
 */

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>
#include <drivers/pwm.h>
#include <sys/printk.h>
#include <sys/__assert.h>
#include <string.h>
#include <stdio.h>

// Refer to dts file
#define GPIO0_NID DT_NODELABEL(gpio0)                      

/**
 * Pin at which BUT1 is connected. Addressing is direct (i.e., pin number)
 */
#define BOARDBUT1 0xb  // Pin at which BUT1 is connected. Addressing is direct (i.e., pin number) 
/**
 * Pin at which BUT2 is connected. Addressing is direct (i.e., pin number)
 */
#define BOARDBUT2 0xc  // Pin at which BUT2 is connected. Addressing is direct (i.e., pin number) 
/**
 * Pin at which BUT3 is connected. Addressing is direct (i.e., pin number)
 */
#define BOARDBUT3 0x18 // Pin at which BUT3 is connected. Addressing is direct (i.e., pin number) 
/**
 * Pin at which BUT4 is connected. Addressing is direct (i.e., pin number)
 */
#define BOARDBUT4 0x19 // Pin at which BUT4 is connected. Addressing is direct (i.e., pin number) 

/**
 * Pin at which BUT5 is connected. Addressing is direct (i.e., pin number)
 */
#define BOARDBUT5 0x03 // Pin at which BUT5 is connected. Addressing is direct (i.e., pin number)
/**
 * Pin at which BUT6 is connected. Addressing is direct (i.e., pin number)
 */
#define BOARDBUT6 0x04 // Pin at which BUT6 is connected. Addressing is direct (i.e., pin number)
/**
 * Pin at which BUT7 is connected. Addressing is direct (i.e., pin number) 
 */ 
#define BOARDBUT7 0x1C // Pin at which BUT7 is connected. Addressing is direct (i.e., pin number) 
/**
 * Pin at which BUT8 is connected. Addressing is direct (i.e., pin number) 
 */
#define BOARDBUT8 0x1D // Pin at which BUT8 is connected. Addressing is direct (i.e., pin number) 

/**
 * Define state S0 = idle
 */
#define S0 0   //idle
/**
 * Define state S1 = coin add
 */
#define S1 1   //coin add
/**
 * Define state S2 = reset/return
 */
#define S2 2   //reset/return
/**
 * Define state S3 = product accepted
 */
#define S3 3   //product accepted
/**
 * Define state S4 = product denied
 */
#define S4 4   //product denied
/**
 * Define state S5 = browse product
 */
#define S5 5   //browse product

// Int related declarations 
static struct gpio_callback but1_cb_data; // Callback structure 
static struct gpio_callback but2_cb_data; // Callback structure 
static struct gpio_callback but3_cb_data; // Callback structure 
static struct gpio_callback but4_cb_data; // Callback structure 
static struct gpio_callback but5_cb_data; // Callback structure 
static struct gpio_callback but6_cb_data; // Callback structure 
static struct gpio_callback but7_cb_data; // Callback structure 
static struct gpio_callback but8_cb_data; // Callback structure 

// Callback function and variables
/**
 * Flag to signal a BUT1 press
 */
volatile int dcToggleFlag = 0;  // Flag to signal a BUT1 press 
/**
 * Flag to signal a BUT2 press
 */
volatile int dcToggleFlag2 = 0; // Flag to signal a BUT2 press 
/**
 * Flag to signal a BUT3 press
 */
volatile int dcToggleFlag3 = 0; // Flag to signal a BUT3 press
/**
 * Flag to signal a BUT4 press
 */ 
volatile int dcToggleFlag4 = 0; // Flag to signal a BUT4 press 
/**
 * Flag to signal a BUT5 press
 */
volatile int dcToggleFlag5 = 0; // Flag to signal a BUT5 press 
/**
 * Flag to signal a BUT6 press
 */
volatile int dcToggleFlag6 = 0; // Flag to signal a BUT6 press 
/**
 * Flag to signal a BUT7 press
 */
volatile int dcToggleFlag7 = 0; // Flag to signal a BUT7 press 
/**
 * Flag to signal a BUT8 press
 */
volatile int dcToggleFlag8 = 0; // Flag to signal a BUT8 press 

/**
 * Function butxpress_cbfunction
 *
 * This function detects if the button was pressed and it prints in the terminal if the button was pressed.
 * It also has a flag that becomes 1 if the button is pressed.
 */
void but1press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins){
    
    // Inform that button was hit
    printk("But1 pressed at %d\n\r", k_cycle_get_32());
    
    // Update Flag
    dcToggleFlag = 1;
}
/**
 * Function butxpress_cbfunction
 *
 * This function detects if the button was pressed and it prints in the terminal if the button was pressed.
 * It also has a flag that becomes 1 if the button is pressed.
 */
void but2press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins){
    
    // Inform that button was hit
    printk("But2 pressed at %d\n\r", k_cycle_get_32());
    
    // Update Flag
    dcToggleFlag2 = 1;
}
/**
 * Function butxpress_cbfunction
 *
 * This function detects if the button was pressed and it prints in the terminal if the button was pressed.
 * It also has a flag that becomes 1 if the button is pressed.
 */
void but3press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins){
    
    // Inform that button was hit
    printk("But3 pressed at %d\n\r", k_cycle_get_32());
    
    // Update Flag
    dcToggleFlag3 = 1;
}
/**
 * Function butxpress_cbfunction
 *
 * This function detects if the button was pressed and it prints in the terminal if the button was pressed.
 * It also has a flag that becomes 1 if the button is pressed.
 */
void but4press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins){
    
    // Inform that button was hit
    printk("But4 pressed at %d\n\r", k_cycle_get_32());
    
    // Update Flag
    dcToggleFlag4 = 1;
}
/**
 * Function butxpress_cbfunction
 *
 * This function detects if the button was pressed and it prints in the terminal if the button was pressed.
 * It also has a flag that becomes 1 if the button is pressed.
 */
void but5press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins){
    
    // Inform that button was hit
    printk("But5 pressed at %d\n\r", k_cycle_get_32());
    
    // Update Flag
    dcToggleFlag5 = 1;
}
/**
 * Function butxpress_cbfunction
 *
 * This function detects if the button was pressed and it prints in the terminal if the button was pressed.
 * It also has a flag that becomes 1 if the button is pressed.
 */
void but6press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins){
    
    // Inform that button was hit
    printk("But6 pressed at %d\n\r", k_cycle_get_32());
    
    // Update Flag
    dcToggleFlag6 = 1;
}
/**
 * Function butxpress_cbfunction
 *
 * This function detects if the button was pressed and it prints in the terminal if the button was pressed.
 * It also has a flag that becomes 1 if the button is pressed.
 */
void but7press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins){
    
    // Inform that button was hit
    printk("But7 pressed at %d\n\r", k_cycle_get_32());
    
    // Update Flag
    dcToggleFlag7 = 1;
}/**
 * Function butxpress_cbfunction
 *
 * This function detects if the button was pressed and it prints in the terminal if the button was pressed.
 * It also has a flag that becomes 1 if the button is pressed.
 */

void but8press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins){
    
    // Inform that button was hit
    printk("But8 pressed at %d\n\r", k_cycle_get_32());
    
    // Update Flag
    dcToggleFlag8 = 1;
}

void StateMachine();
void ConfigurePins();

/**
 * Function main
 *
 * This function is the main function of the project.
 * It calls two functions, function ConfigurePins() and function StateMachine().
 */ 
void main(void) {
    ConfigurePins();
    StateMachine();

    return;
}

/**
 * Function ConfigurePins
 *
 * This function configure and iniatialize all the pins that are used in this
 * project.
 */
void ConfigurePins() {
    // Local vars
    const struct device *gpio0_dev;     // Pointer to GPIO device structure 
    const struct device *pwm0_dev;      // Pointer to PWM device structure 
    int ret=0;                          // Generic return value variable 
    int ret2= 0;                        // Generic return value variable 
    int ret3= 0;                        // Generic return value variable 
    int ret4= 0;                        // Generic return value variable 
    int ret5= 0;                        // Generic return value variable 
    int ret6= 0;                        // Generic return value variable 
    int ret7= 0;                        // Generic return value variable 
    int ret8= 0;                        // Generic return value variable 

    // Bind to GPIO 0 and PWM0
    gpio0_dev = device_get_binding(DT_LABEL(GPIO0_NID));
    if (gpio0_dev == NULL) {
        printk("Error: Failed to bind to GPIO0\n\r");        
	return;
    }
    else {
        printk("Bind to GPIO0 successfull \n\r");        
    }

    // Configure PINS
    ret = gpio_pin_configure(gpio0_dev, BOARDBUT1, GPIO_INPUT | GPIO_PULL_UP);
    if (ret < 0) {
        printk("Error %d: Failed to configure BUT 1 \n\r", ret);
	return;
    }
    ret2 = gpio_pin_configure(gpio0_dev, BOARDBUT2, GPIO_INPUT | GPIO_PULL_UP);
    if (ret2 < 0) {
        printk("Error %d: Failed to configure BUT 2 \n\r", ret);
	return;
    }
    ret3 = gpio_pin_configure(gpio0_dev, BOARDBUT3, GPIO_INPUT | GPIO_PULL_UP);
    if (ret3 < 0) {
        printk("Error %d: Failed to configure BUT 3 \n\r", ret);
	return;
    }
    ret4 = gpio_pin_configure(gpio0_dev, BOARDBUT4, GPIO_INPUT | GPIO_PULL_UP);
    if (ret4 < 0) {
        printk("Error %d: Failed to configure BUT 4 \n\r", ret);
	return;
    }
    ret5 = gpio_pin_configure(gpio0_dev, BOARDBUT5, GPIO_INPUT | GPIO_PULL_UP);
    if (ret5 < 0) {
        printk("Error %d: Failed to configure BUT 5 \n\r", ret);
	return;
    }
    ret6 = gpio_pin_configure(gpio0_dev, BOARDBUT6, GPIO_INPUT | GPIO_PULL_UP);
    if (ret6 < 0) {
        printk("Error %d: Failed to configure BUT 6 \n\r", ret);
	return;
    }
    ret7 = gpio_pin_configure(gpio0_dev, BOARDBUT7, GPIO_INPUT | GPIO_PULL_UP);
    if (ret7 < 0) {
        printk("Error %d: Failed to configure BUT 7 \n\r", ret);
	return;
    }
    ret8 = gpio_pin_configure(gpio0_dev, BOARDBUT8, GPIO_INPUT | GPIO_PULL_UP);
    if (ret8 < 0) {
        printk("Error %d: Failed to configure BUT 8 \n\r", ret);
	return;
    }

    // Set interrupt HW - which pin and event generate interrupt 
    ret = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT1, GPIO_INT_EDGE_TO_ACTIVE);
    if (ret != 0) {
	printk("Error %d: failed to configure interrupt on BUT1 pin \n\r", ret);
	return;
    }
    ret2 = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT2, GPIO_INT_EDGE_TO_ACTIVE);
    if (ret2 != 0) {
	printk("Error %d: failed to configure interrupt on BUT2 pin \n\r", ret);
	return;
    }
    ret3 = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT3, GPIO_INT_EDGE_TO_ACTIVE);
    if (ret3 != 0) {
	printk("Error %d: failed to configure interrupt on BUT3 pin \n\r", ret);
	return;
    }
    ret4 = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT4, GPIO_INT_EDGE_TO_ACTIVE);
    if (ret4 != 0) {
	printk("Error %d: failed to configure interrupt on BUT4 pin \n\r", ret);
	return;
    }
    ret5 = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT5, GPIO_INT_EDGE_TO_ACTIVE);
    if (ret5 != 0) {
	printk("Error %d: failed to configure interrupt on BUT5 pin \n\r", ret);
	return;
    }
    ret6 = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT6, GPIO_INT_EDGE_TO_ACTIVE);
    if (ret6 != 0) {
	printk("Error %d: failed to configure interrupt on BUT6 pin \n\r", ret);
	return;
    }
    ret7 = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT7, GPIO_INT_EDGE_TO_ACTIVE);
    if (ret7 != 0) {
	printk("Error %d: failed to configure interrupt on BUT7 pin \n\r", ret);
	return;
    }
    ret8 = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT8, GPIO_INT_EDGE_TO_ACTIVE);
    if (ret8 != 0) {
	printk("Error %d: failed to configure interrupt on BUT8 pin \n\r", ret);
	return;
    }
    
    // Set callback 
    gpio_init_callback(&but1_cb_data, but1press_cbfunction, BIT(BOARDBUT1));
    gpio_init_callback(&but2_cb_data, but2press_cbfunction, BIT(BOARDBUT2));
    gpio_init_callback(&but3_cb_data, but3press_cbfunction, BIT(BOARDBUT3));
    gpio_init_callback(&but4_cb_data, but4press_cbfunction, BIT(BOARDBUT4));
    gpio_init_callback(&but5_cb_data, but5press_cbfunction, BIT(BOARDBUT5));
    gpio_init_callback(&but6_cb_data, but6press_cbfunction, BIT(BOARDBUT6));
    gpio_init_callback(&but7_cb_data, but7press_cbfunction, BIT(BOARDBUT7));
    gpio_init_callback(&but8_cb_data, but8press_cbfunction, BIT(BOARDBUT8));
    gpio_add_callback(gpio0_dev, &but1_cb_data);
    gpio_add_callback(gpio0_dev, &but2_cb_data);
    gpio_add_callback(gpio0_dev, &but3_cb_data);
    gpio_add_callback(gpio0_dev, &but4_cb_data);
    gpio_add_callback(gpio0_dev, &but5_cb_data);
    gpio_add_callback(gpio0_dev, &but6_cb_data);
    gpio_add_callback(gpio0_dev, &but7_cb_data);
    gpio_add_callback(gpio0_dev, &but8_cb_data);

    return;
}

/**
 * Function StateMachine
 *
 * This function implements the state machine of a vending machine.
 * It is made of a switch case that is going to change cases in different conditions.
 */
void StateMachine() {
    int printflag =  0;
    int i         =  0;
    int value     =  0;
    int state     = S0;

    int reset      = 0;
    int browseup   = 0;
    int browsedown = 0;
    int selproduct = 0;
    int coin10     = 0;
    int coin20     = 0;
    int coin50     = 0;
    int coin100    = 0;

    int coin10value  =  10;
    int coin20value  =  20;
    int coin50value  =  50;
    int coin100value = 100;

    int selproductvalue[] = {150, 100, 50};
    char *product[]       = {"Beer", "Tuna Sandwich", "Coffee"};

    while(1) { 
      browsedown = dcToggleFlag;
      selproduct = dcToggleFlag2;
      browseup   = dcToggleFlag3;
      reset      = dcToggleFlag4;
      coin10     = dcToggleFlag5;
      coin20     = dcToggleFlag6;
      coin50     = dcToggleFlag7;
      coin100    = dcToggleFlag8;

        
      switch (state) {
      case S0:
        if(printflag == 0){
          printk("\n\n\nCreditos: %u  \n\r", value);
          printk("Produto selecionado: %s \n\r", product[i]);
          printk("Preco:    %u \n\n\r", selproductvalue[i]);
          printflag = 1;
        }
        
        if(coin10 == 1 || coin20 == 1 || coin50 == 1 || coin100 == 1){
          state = S1;
          printflag = 0;
        }
        if(reset == 1){
          state = S2;
          printflag = 0;
        }
        if(selproduct == 1){
          printflag = 0;
          if(value >= selproductvalue[i]) state = S3;
          else state = S4;
        }
        if(browseup){
          printflag = 0;
          state = S5;
        }
        if(browsedown){
          printflag = 0;
          state = S5;
        }
        break;

      case S1:
        if(coin10  == 1){  
          printk("\n\n\n 10 Creditos adicionados.");
          value += coin10value;
        }
        if(coin20  == 1){  
          value += coin20value;
          printk("\n\n\n 20 Creditos adicionados.");
        }
        if(coin50  == 1){  
          value += coin50value;
          printk("\n\n\n 50 Creditos adicionados.");
        }
        if(coin100 == 1){  
          value += coin100value;
          printk("\n\n\n 100 Creditos adicionados.");
        }
        state = S0;
        dcToggleFlag5 = 0;
        dcToggleFlag6 = 0;
        dcToggleFlag7 = 0;
        dcToggleFlag8 = 0;

        break;

      case S2:
        value = 0;
        printk("\n\n\n Creditos devolvidos.");
        state = S0;
        dcToggleFlag4 = 0;

        break;

      case S3:
        value -= selproductvalue[i];
        printk("\n\n\n Compra efetuada.");
        state = S0;
        dcToggleFlag2 = 0;

        break;

      case S4:
        printk("\n\n\n Creditos insuficientes.");
        state = S0;
        dcToggleFlag2 = 0;

        break;

      case S5:
        if(browseup == 1 && i <= 2) i++;
        if(browseup == 1 && i >  2) i = 0;
        
        if(browsedown == 1 && i >= 0) i--;
        if(browsedown == 1 && i <  0) i = 2;
            
        state = S0;
        dcToggleFlag = 0;
        dcToggleFlag3 = 0;          
        
        break;
      }      
    }       
    return;
}
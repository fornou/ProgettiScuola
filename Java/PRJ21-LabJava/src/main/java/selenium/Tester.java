package selenium;

import java.util.Random;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.support.ui.Select;

public class Tester {
	
	public static void main(String[] args) {
		WebDriver driver = new ChromeDriver();
		
		for(int i = 0; i < 10; i++) {
			aggiungi(driver);
		}
		//driver.quit();
	}

	private static void aggiungi(WebDriver driver) {
		driver.get("http://localhost:8080/PRJ21-LabJava/");
		
		double random = Math.random();
		
		if(random< 0.33) {
			WebElement radioMaglia = driver.findElement(By.id("maglia"));
			radioMaglia.click();
		}else
    	if(random<0.66) {
    		WebElement radioGiacca = driver.findElement(By.id("giacca"));
    		radioGiacca.click();
    	}else {
    		WebElement radioPantalone = driver.findElement(By.id("pantalone"));
    		radioPantalone.click();
    	}
			
		WebElement prezzo = driver.findElement(By.id("prezzo"));
		Random rand = new Random();
		double val = rand.nextDouble(10, 50);
		prezzo.sendKeys(""+Math.round(val));
		
		WebElement seleElement = driver.findElement(By.id("taglia"));
		Select select = new Select(seleElement);
		
		select.selectByIndex(rand.nextInt(1, 5));
		
		WebElement submit = driver.findElement(By.id("submit"));
		
		submit.click();
	}

}

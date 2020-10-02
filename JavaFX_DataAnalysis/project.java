import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Hashtable;
import java.util.List;
import java.util.Set;
import java.util.Map.Entry;

import javax.swing.JFrame;
import java.awt.FileDialog;
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.beans.property.SimpleStringProperty;
import static java.util.Comparator.comparing;
import static java.util.stream.Collectors.toList;

public class project extends Application {
   Stage window;
   Scene scene1, scene3, numberofdata, numberofcol;
   int numberofdatas=0;

   // Global Statistic variables
   public static String mean = "";
   public static String median = "";
   public static String mode = "";
   public static String top3 = "";
   public static Hashtable<String, Double> percentileTable;

   public class dataset
   {
      private final SimpleStringProperty firstName;

      private dataset(String fName)
      {
         this.firstName = new SimpleStringProperty(fName);
      }

      public String getFirstName()
      {
         return firstName.get();
      }
      public void setfirstName(String fName)
      {
         firstName.set(fName);
      }
   }

   @Override
   public void start(Stage primaryStage) throws Exception 
   {
      
      //Set the primary stage to be the main window
      window = primaryStage;

      //Setting the title to Stage.
      window.setTitle("Data Analytics");

      //call mainScene
      scene1 = mainScreen();

      //Adding the scene to Stage
      window.setScene(scene1);

      //Displaying the contents of the stage
      window.show();
   }

   //Get user file path
   public String getUserFile(){
      String fileName = "";
      FileDialog fd = new FileDialog(new JFrame());
      fd.setVisible(true);
      File[] f = fd.getFiles();
      if(f.length > 0){
         fileName = fd.getFiles()[0].getAbsolutePath();
         
         int length = fileName.length(); 
         String extention = fileName.substring(length - 4, length);

         if(extention.trim().equals(".txt")){
            return fileName;
         } else {
            fileName = "";
         }
      }

      return fileName;
   }
   
   // Get file line count
   public int fileLineCount(String fileName){
      String input = "";
      int lineCount = 0;
      try(BufferedReader reader = new BufferedReader(new FileReader(new File(fileName)))){
          // Get number of lines in file
         while ((input = reader.readLine()) != null){
            lineCount++;
         }
      }catch(IOException e){
         e.printStackTrace();
      }
      return lineCount;
   }

   // Read in file
   public Float[] readFile(String fileName, int lineCount){
      String input = "";
      Float dataContent[];
      dataContent = new Float[lineCount];

      try(BufferedReader reader = new BufferedReader(new FileReader(new File(fileName)))){
         // Iterate through file contents and store into array
         for(int i = 0; i < lineCount; i++)
         {
            input = reader.readLine();
            
            try
            {
               Float convertInput = Float.parseFloat(input);
               dataContent[i] = convertInput;
            }catch(NumberFormatException e){
               // if not a float, skip and continue to next line
               reader.skip(0);
            }
   
         }

      }catch(IOException e)
      {
         e.printStackTrace();
      }
      return dataContent;
   }


   /* ==== FUNCTION FOR MAIN SCENE ==== */
   public Scene mainScreen(){

      // === Components ===
      //Create a title for the main pagee
      Label title = new Label("Data Analytics");
      //Create a error label that will take in any error
      Label error = new Label("");

      
      //IMPORT DATA SET Button
      Button importButton = new Button("Import Data Set");
      importButton.setOnAction(event -> {
         String file = getUserFile();
         // check if no file returned
         if(file != "")
         {
            // window.setScene(thirdScene(file));
            window.setScene(secondaryScene(file));
         }
         else
         {
            error.setText("File must be of type .txt");
         }

      });
      
      //CREATE NEW SET Button
      Button createButton = new Button("Create New Data Set");

      //Build Scene upon button click
      createButton.setOnAction(event ->{
         // window.setScene(thirdScene(""));
         window.setScene(secondaryScene(""));
      });

      // === LAYOUTS ===
      VBox layout = new VBox(80);
      VBox header = new VBox(0); // holds Title and error
      VBox buttonBox = new VBox(20); // holds buttons

      layout.getChildren().addAll(header, buttonBox);
      header.getChildren().addAll(title, error);
      buttonBox.getChildren().addAll(importButton, createButton);

      header.setAlignment(Pos.TOP_CENTER);
      buttonBox.setAlignment(Pos.CENTER);

      layout.getStyleClass().add("root");
      layout.getStyleClass().add("layout1");

      title.getStyleClass().add("title");

      importButton.getStyleClass().add("custom-button");
      createButton.getStyleClass().add("custom-button");
      error.getStyleClass().add("error");
      
      //Create scene
      scene1 = new Scene(layout, 400, 400);
      scene1.getStylesheets().add("stylesheet.css");

      //Set max height and width of stage
      window.setMaxWidth(600);
      window.setMaxHeight(400);

      return scene1;
   }
   
   // /* ==== FUNCTION FOR SECOND SCENE ==== */
   public Scene secondaryScene(String fileName){
      ObservableList<dataset> input = FXCollections.observableArrayList();
      TableView<dataset> table = new TableView<dataset>();
      Float dataContent[];
      dataContent = new Float[numberofdatas];

      Label error = new Label("");
      //if imported file, read data from and store data into array
      if(fileName != ""){
         int lineCount = fileLineCount(fileName);
         Float[] data = readFile(fileName, lineCount);
         System.out.println(data.length);

         for(int i = 0; i < data.length; i++) // prints out the imported data
         {
            System.out.println(data[i]);
            input.add(new dataset(String.valueOf(data[i]))); 
            numberofdatas++;
         }
      }
     
      Label title = new Label("Data Set");
      title.getStyleClass().add("title");

      TextField datainput = new TextField();

      Button enterdataButton = new Button("Enter the new Data");
      Button deletedataButton = new Button("Delete Data");
      Button submitforanalysis = new Button("Submit For Analysis");

      submitforanalysis.setOnAction(event ->{
         //send to submit for analysis
         if(numberofdatas < 1) {
            error.setText("Please enter data to submit for analysis");
            return;
         }
         else {
            window.setScene(thirdScene(fileName, input));
         }
      });

      table.setEditable(true);

      TableColumn valuecol = new TableColumn("Data");
      valuecol.setMinWidth(100);
      valuecol.setCellValueFactory(new PropertyValueFactory<dataset,String>("firstName"));
      
      table.setItems(input);
      table.getColumns().addAll(valuecol);
      

      enterdataButton.setOnAction(event ->{
         //input entered data into array
         try
            {
                  Float floateddata = Float.parseFloat(datainput.getText());
                  Float incoming = floateddata;
                  input.add(new dataset(String.valueOf(incoming))); 
                  numberofdatas++;
                  error.setText("");
                  datainput.clear();
            }catch(NumberFormatException e){
               // if not a float, skip and continue to next line
               error.setText("Please only enter float values");
            }
      });
      deletedataButton.setOnAction(event ->{
         //input entered data into array
                  
         dataset selectedItem = table.getSelectionModel().getSelectedItem();
         table.getItems().remove(selectedItem);
      });

      // == LAYOUTS ==
      VBox layout = new VBox(80);
      VBox header = new VBox(0); // holds Title and error
      VBox content = new VBox(20); // holds buttons
      VBox datadisplay = new VBox(50);

      layout.getChildren().addAll(header, content,datadisplay);
      header.getChildren().addAll(title, error);
      content.getChildren().addAll(enterdataButton, deletedataButton,datainput,submitforanalysis);
      datadisplay.getChildren().addAll(table);

      header.setAlignment(Pos.TOP_CENTER);
      content.setAlignment(Pos.CENTER);
      datadisplay.setAlignment(Pos.BOTTOM_CENTER);

      layout.getStyleClass().add("root");
      layout.getStyleClass().add("layout1");
      enterdataButton.getStyleClass().add("custom-button");
      deletedataButton.getStyleClass().add("custom-button");
      submitforanalysis.getStyleClass().add("custom-button");
      error.getStyleClass().add("error");
      table.getStyleClass().add("custom-button");

      Scene scene2 = new Scene(layout, 400, 700);
      scene2.getStylesheets().add("stylesheet.css");

      //Set max height and width of stage
      window.setMaxWidth(1200);
      window.setMaxHeight(1200);

      return scene2;
   }

   /* ==== FUNCTION FOR SECOND SCENE ==== */
   public Scene thirdScene(String fileName, ObservableList<dataset> input){
      System.out.println(numberofdatas);
      
      // Create mutable array of our dataset to pass to stats functions
      String[] data = new String[input.size()];
      for(int i = 0; i < data.length; i++) {
         data[i] = input.get(i).firstName.getValue();
      }

      GetStatistic(data);

      // System.out.println("Printing Stats!!!");
      // System.out.println(mean);
      // System.out.println(median);
      // System.out.println(mode);
      // System.out.println(top3);
      // System.out.println(percentileTable);
      
      TableView<dataset> dataTable = new TableView<dataset>();
      TableView<dataset> statsTable = new TableView<dataset>();
      
      /* ==== LABELS ==== */
      Label error = new Label("");

      Label title = new Label("Data Analysis");
      title.getStyleClass().add("title");
      
      Label dataTableLabel= new Label("Entered Data");
      dataTableLabel.getStyleClass().add("table-title");
      
      Label statsTableLabel = new Label("Statistical Distribution");
      statsTableLabel.getStyleClass().add("table-title");
      
      Label meanLabel = new Label("Mean: " + mean);
      meanLabel.getStyleClass().add("stats-label");
      
      Label medianLabel = new Label("Median:" + median);
      medianLabel.getStyleClass().add("stats-label");

      Label modeLabel = new Label("Mode: " + mode);
      modeLabel.getStyleClass().add("stats-label");
      
      Label top3Label = new Label("Top 3 Recurring: " + top3);
      top3Label.getStyleClass().add("stats-label");
      
      
      /* ==== BUTTONS ==== */
      MenuButton displayButton = new MenuButton("Display");
      MenuItem horizontal = new MenuItem("Horizontal");
      MenuItem vertical = new MenuItem("Vertical");
      displayButton.getItems().addAll(horizontal, vertical);
      // displayButton.getStyleClass().add("dropdown-button");

      horizontal.setOnAction(event -> {
         System.out.println("converting table to horizontal view...");
      });
      
      vertical.setOnAction(event -> {
         System.out.println("converting table to vertical view...");
      });

      MenuButton sortButton = new MenuButton("Sort By");
      MenuItem ascending = new MenuItem("Ascending");
      MenuItem descending = new MenuItem("Descending");
      sortButton.getItems().addAll(ascending, descending);
      // sortButton.getStyleClass().add("dropdown-button");

      // Sort list in ascending order
      ascending.setOnAction(event -> {
         input.sort((a, b) ->
            Double.compare(
               new Double(a.getFirstName()),
               new Double(b.getFirstName())
            )
         );
      });

      // Sort list in descending order
      descending.setOnAction(event -> {
         input.sort((a, b) ->
            Double.compare(
               new Double(b.getFirstName()),
               new Double(a.getFirstName())
            )
         );
      });

      Button saveButton = new Button("Save");

      saveButton.setOnAction(event ->{
         File file = new File("Output.txt");
            //Instantiating the PrintStream class
            try
            {
               PrintStream stream = new PrintStream(file);
               System.setOut(stream);
            }
            catch(FileNotFoundException e)
            {
               System.out.println("There has been an issue finding the file.");
            }
            //Printing values to file
            for(int i = 0; i < data.length; i++) {
               System.out.println(data[i]);
            }
      });


      /* ==== TABLES ==== */
      dataTable.setEditable(true);
      statsTable.setEditable(true);

      TableColumn<dataset, String> dataCol = new TableColumn<>("filler");
      dataCol.setMinWidth(80);
      dataCol.setCellValueFactory(new PropertyValueFactory<dataset,String>("firstName"));
      
      dataTable.setItems(input);
      dataTable.getColumns().addAll(dataCol);

      for(Integer i = 1; i <= 10; i++) {
         String colName = "";
         if(i == 1) {
            colName = "0 - 10%";
         }
         else {
            Integer temp1 = ((i-1) * 10 + 1);
            Integer temp2 = i * 10 ;
            colName = temp1.toString() + " - " + temp2 + "%";
         }

         TableColumn<dataset, String> statsCol = new TableColumn<>(colName);
         statsCol.setMinWidth(70);
         statsCol.setCellValueFactory(new PropertyValueFactory<dataset,String>("firstName"));

         statsTable.getColumns().add(statsCol);
         
      }

      System.out.println(percentileTable.values());
      statsTable.setItems(input);

      // == LAYOUTS ==
      VBox layout = new VBox(80);
      VBox header = new VBox(0); // holds Title and error
      HBox content = new HBox(10); // holds buttons
      HBox dataTableDisplay = new HBox(10); // holds buttons
      VBox statsTableDisplay = new VBox(10);
      HBox statsDisplay = new HBox(60);

      layout.getChildren().addAll(header, content,dataTableDisplay,statsTableDisplay,statsDisplay);
      header.getChildren().addAll(title, error);
      content.getChildren().addAll(displayButton, sortButton);
      dataTableDisplay.getChildren().addAll(dataTableLabel, dataTable);
      statsTableDisplay.getChildren().addAll(statsTableLabel, statsTable);
      statsDisplay.getChildren().addAll(meanLabel, medianLabel, modeLabel, top3Label, saveButton);

      header.setAlignment(Pos.TOP_CENTER);
      content.setAlignment(Pos.TOP_RIGHT);
      dataTableDisplay.setAlignment(Pos.TOP_LEFT);
      statsTableDisplay.setAlignment(Pos.TOP_LEFT);
      statsDisplay.setAlignment(Pos.BOTTOM_LEFT);

      layout.getStyleClass().add("root");
      layout.getStyleClass().add("layout1");
      saveButton.getStyleClass().add("custom-button");
      error.getStyleClass().add("error");
      dataTable.getStyleClass().add("custom-button");
      statsTable.getStyleClass().add("custom-button");

      scene3 = new Scene(layout, 900, 700);
      scene3.getStylesheets().add("stylesheet.css");

      //Set max height and width of stage
      window.setMaxWidth(1200);
      window.setMaxHeight(1200);
      window.setMinWidth(1500);
      window.setMinHeight(800);

      return scene3;
   }   


   /* ==== DETERMINES THE NUMBER OF COLUMNS FOR THE TABLE ==== */
   public Scene numberofcolumns(String fileName){
      Label error = new Label("");
      
     
      Label title = new Label("Number of Columns of Table");
      title.getStyleClass().add("title");
  
      TextField datainput = new TextField();
  
      Button numberofcolButton = new Button("Enter");
      numberofcolButton.setOnAction(event ->{
         //input entered data into array
         try
            {
               int intdata = Integer.parseInt(datainput.getText());
               int incoming = intdata;
               System.out.println(incoming);
               // window.setScene(secondaryScene(fileName, incoming));
            }catch(NumberFormatException e){
               // if not a float, skip and continue to next line
               error.setText("Please only enter integer values");
            }
      });
  
      // == LAYOUTS ==
      VBox layout = new VBox(80);
      VBox header = new VBox(0); // holds Title and error
      VBox content = new VBox(20); // holds buttons
  
      layout.getChildren().addAll(header, content);
      header.getChildren().addAll(title, error);
      content.getChildren().addAll(numberofcolButton,datainput);
  
      header.setAlignment(Pos.TOP_CENTER);
      content.setAlignment(Pos.CENTER);
  
      layout.getStyleClass().add("root");
      layout.getStyleClass().add("layout1");
      numberofcolButton.getStyleClass().add("custom-button");
      error.getStyleClass().add("error");
  
      numberofcol = new Scene(layout, 400, 400);
      numberofcol.getStylesheets().add("stylesheet.css");
  
      //Set max height and width of stage
      window.setMaxWidth(1200);
      window.setMaxHeight(800);
  
      return numberofcol;
   }

   public static Hashtable<String, Integer> GetStatistic(String[] newStats) {

      Hashtable<String, Integer> statistics = new Hashtable<String, Integer>();

      for (String stat : newStats) {
         if (statistics.get(stat) == null) {
            statistics.put(stat, 1);
         } else {
            Integer count = statistics.get(stat);
            statistics.put(stat, count + 1);
         }
      }

      calculateMean(newStats);
      calculateMedian(newStats);
      calculateMode(statistics);
      calculateTop3Recurring(statistics);
      calculatePercentile(newStats);

      return statistics;
   }

   public static void calculateMean(String[] input) {
      if(input.length > 1) {
         DecimalFormat df = new DecimalFormat("#.##");
         df.setRoundingMode(RoundingMode.FLOOR);

         double[] stats = Arrays.stream(input)
         .mapToDouble(Double::parseDouble)
         .toArray();

         Double temp = 0.0;
         for(Double stat : stats) {
            temp += stat;
         }
         temp /= stats.length;

         mean = new Double(df.format(temp)).toString();
      }
   }

   public static void calculateMedian(String[] input) {
      if(input.length > 1) {
         DecimalFormat df = new DecimalFormat("#.##");
         df.setRoundingMode(RoundingMode.FLOOR);

         double[] stats = Arrays.stream(input)
         .mapToDouble(Double::parseDouble)
         .sorted()
         .toArray();

         Integer medianPosition;
         Double temp;

         if(stats.length % 2 == 0) {
            medianPosition = stats.length / 2;
            temp = (stats[medianPosition] + stats[medianPosition+1] / 2);
            df.format(temp);
         }
         else {
            medianPosition = (stats.length / 2) + 1;
            temp = stats[medianPosition];
         }

         median = new Double(temp).toString();
      }
   }

   public static void calculateMode(Hashtable<String, Integer> statistics) {
      Integer maxOccurences = Collections.max(statistics.values());

      if (maxOccurences > 1) {
         Double temp = 0.0;

         List<String> multiModalArray = new ArrayList<String>();
         
         for (Entry<String, Integer> entry : statistics.entrySet()) {
            if(maxOccurences == 1) {
               System.out.println("Disclaimer: There are no repeating elements.");
               return;
            }
            if (entry.getValue() == maxOccurences) {
               temp = new Double(entry.getKey());     // Set mode equal to the key with the maximum occurences
               multiModalArray.add(entry.getKey());
            }
         }

         System.out.println("\nMax Occurences: " + maxOccurences);
         if(multiModalArray.size() > 1) {
            System.out.println("Disclaimer: Multimodal data set. There are " + multiModalArray.size() + " modes.");
            System.out.println("Mode: " + multiModalArray);
         }
         else {
            System.out.println(multiModalArray);
            System.out.println("Mode: " + temp);
         }

         String modeString = "";

         for(int i = 0; i < multiModalArray.size(); i++) {
            if(multiModalArray.size() == 1) {
               modeString += multiModalArray.get(i);
            }
            else if(i == multiModalArray.size()-1 && multiModalArray.size() > 1) {
               modeString += multiModalArray.get(i);
            }
            else {
               modeString += multiModalArray.get(i) + ", ";
            }
         }
         
         mode = modeString;
      }
      else {
         mode = "N/A";
      }
   }

   public static void calculateTop3Recurring(Hashtable<String, Integer> statistics) {
      // Remove all elements that have a value of one.
      statistics.values().removeAll(Collections.singleton(1));

      if (statistics.size() >= 3) {
         Set<Entry<String, Integer>> list = statistics.entrySet();

         // This will sort the entry set by assigned value of each entry.
         // it will then cut the rest of the elements from the collection,
         // leaving the highest 3 elements in ascending order.
         List<Entry<String, Integer>> top3TempList = list.stream()
         .sorted(comparing(Entry::getValue))
         .skip(list.size()-3)
         .collect(toList());

         List<String> top3Recurring = new ArrayList<String>();
         for(int i = 0; i < top3TempList.size(); i++) {
            top3Recurring.add(top3TempList.get(i).getKey());
         }

         System.out.println("\n" + top3TempList);
         System.out.println(top3Recurring);

         String top3Str = "";

         for(int i = 0; i < top3Recurring.size(); i++) {
            if(top3Recurring.size() == 1) {
               top3Str += top3Recurring.get(i);
            }
            else if(i == top3Recurring.size()-1 && top3Recurring.size() > 1) {
               top3Str += top3Recurring.get(i);
            }
            else {
               top3Str += top3Recurring.get(i) + ", ";
            }
         }

         top3 = top3Str;
      }
      else {
         top3 = "Not enough recurring elements";
         return;
      }
   }

   public static void calculatePercentile(String[] input) {
      if(input.length > 1) {
         DecimalFormat df = new DecimalFormat("#.##");
         df.setRoundingMode(RoundingMode.FLOOR);

         double[] stats = Arrays.stream(input)
         .mapToDouble(Double::parseDouble)
         .sorted()
         .toArray();

         Hashtable<String, Double> percentiles = new Hashtable<String, Double>();

         // In order to capture each individual percentile to include duplicates
         // the percentile is used for the key value for each element in the hashtable
         for(int i = 0; i < stats.length; i++) {
            Double temp = (i / new Double(stats.length-1)) * 100;
            df.format(temp);
            String key = Double.toString(temp);
            percentiles.put(key, stats[i]);
         }

         percentileTable = percentiles;
      }
   }

   public static void main(String args[])
   {
      launch(args);
   }
}

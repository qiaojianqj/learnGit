package com.proxy;
 
public class ReportGeneratorImpl implements ReportGenerator {
 
    public ReportGeneratorImpl(){
        System.out.println("ReportGeneratorImpl instance created");
    }
    
    @Override
    public void displayReportTemplate(String reportFormat, int reportEntries) {
        //retain blank, let proxy do the displaying
    }
    
    @Override
    public void  generateComplexReport(String reportFormat, int reportEntries){
        System.out.println("ReportGeneratorImpl: Generating complex report in " + reportFormat + " format with " + reportEntries + " entries");
 
    }
    
    @Override
    public void  generateSensitiveReport(){
        System.out.println("ReportGeneratorImpl: Generating sensitive report");
    }
 
}
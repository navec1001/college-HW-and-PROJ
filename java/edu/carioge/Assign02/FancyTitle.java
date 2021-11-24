package edu.carioge.Assign02;

public class FancyTitle {
    public static int countFibSteps(int maxVal) {
        if (maxVal <= 1)
            return 0;
        int steps = 0;
        int curNum = 1;
        int preNum = 1;
        int newNum = 0;
        while (curNum < maxVal)
        {
            newNum = curNum + preNum;
            preNum = curNum;
            curNum = newNum;
            steps += 1;
        }
        return steps;
    }
    public static String repeatChar(char c, int cnt) {
        String output = "";
        for (int i = 0 ; i < cnt ; i++){
            output += c;
        }
        return output;
    }
    public static String [] makeFibStringList(char c, int levels) {
        String [] output = new String[levels];
        int curNum = 1;
        int preNum = 1;
        int newNum = 0;
        for (int i = 0; i < levels; i++) {
            output[i] = repeatChar(c, curNum);
            newNum = curNum + preNum;
            preNum = curNum;
            curNum = newNum;
        }
        return output;
    }
    public static String makeFilledCenterString(String border, int desiredLen) {
        int bLen = border.length();
        int numSpaces = desiredLen - 2*(bLen);
        String allSpace = repeatChar(' ', numSpaces);
        return border + allSpace + border;
    }
    public static String [] makeFooter(char c, int desiredLen) {
        int numLevels = countFibSteps(desiredLen/2);
        String [] levels = new String[numLevels];
        levels = makeFibStringList(c, numLevels);
        for (int i = 0; i < levels.length; i++ ) {
            levels[i] = makeFilledCenterString(levels[i], desiredLen);
        }
        return levels;
    }
    public static String createFancyTitle(String message, char c) {
        int desiredLen = message.length() + 4;
        String [] footer = makeFooter(c, desiredLen);
        String output = "";
        output += repeatChar(c, desiredLen);
        output += "\n";
        for (int i = footer.length - 1; i >= 0; i--) {
            output += footer[i];
            output += "\n";
        }
        output += c;
        output += " ";
        output += message;
        output += " ";
        output += c;
        output += "\n";
        for (int i = 0; i < footer.length; i++) {
            output += footer[i];
            output += "\n";
        }
        output += repeatChar(c, desiredLen);
        output += "\n";
        return output;
    }
}

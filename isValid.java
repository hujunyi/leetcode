public class S65 {

  public static void main(String[] args) {

  }

  public boolean isNumber(String s) {
    if(s.trim().isEmpty()){
      return false;
    }
    String regex = "\\s*[-+]?(\\d+\\.?|\\.\\d+)\\d*(e[-+]?\\d+)?\\s*";
    :q
    if(s.trim().matches(regex)){
      return true;
    }else{
      return false;
    }
  }
}


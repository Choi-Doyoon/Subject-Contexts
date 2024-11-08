public class weather {
    public static void main(String[] args){
        double temperature; //기온
        double precipitation; //강수량
        double snowfall; //적설량
        double windspeed; //풍속->평균풍속
        double humidity; //습도->상대습도
        double daylighttime; //일조시간
        double cloudcover; //운량
        String weather;

        cloudcover=2.0;
        if(cloudcover>=0 &&cloudcover<3){
            System.out.println("맑음");
        }
        else if(cloudcover>=3 &&cloudcover<6){
            System.out.println("구름조금");
        }
        else if(cloudcover>=6 &&cloudcover<9){
            System.out.println("구름많음");
        }
        else if(cloudcover>=9){
            System.out.println("흐림");
        }

        if(temperature>=31 &&temperature<33){
            System.out.println("관심");
        }
        else if(temperature>=33&&temperature<35){
            System.out.println("폭염주의");
        }
        else if(temperature>=35 && temperature<38){
            System.out.println("폭염");
        }
        else if(temperature>=38){
            System.out.println("위험");
        }
        else{
            System.out.println("괜찮다.");
        }
    }
}

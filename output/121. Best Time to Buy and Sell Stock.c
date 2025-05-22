int maxProfit(int* prices, int pricesSize) {

    int sell_price = 0;
    int now = prices[0];
    for(int i=1;i<pricesSize;i++){
        if(prices[i]<now){
            now = prices[i];
        }
        else{
            sell_price = ((prices[i]-now)>sell_price?(prices[i]-now):sell_price);
        }

    }
    return sell_price;
    
}
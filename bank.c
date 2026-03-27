#include<stdio.h>
#include<stdlib.h>
struct account{
    int accNo;
    char name[50];
    float balance;
};
int main()
{
    struct account a;
    int choice;
    FILE*fp;
    while(1){
    printf("\n---BANK MENU---\n");
    printf("1.Create Account\n");
    printf("2.Deposit Money\n");
    printf("3.Withdraw Money\n");
    printf("4.Check Balance\n");
    printf("5.Exit\n");
    printf("Enter choice:");
    scanf("%d",&choice);


    switch(choice){
    case 1:
        fp=fopen("bank.txt","w");
        printf("Enter Account Number:");
        scanf("%d",&a.accNo);
        printf("Enter Name:");
        scanf("%s",a.name);
        printf("Enter Initial Balance:");
        scanf("%f",&a.balance);

        fwrite(&a,sizeof(a),1,fp);
        fclose(fp);
        printf("Account created successfully!\n");
        break;

    case 2:
        fp=fopen("bank.txt","r+");
        fread(&a,sizeof(a),1,fp);

        float deposit;
        printf("Enter amount to deposit:");
        scanf("%f",&deposit);
        if(deposit>0){
                a.balance+=deposit;
        rewind(fp);
        fwrite(&a,sizeof(a),1,fp);
        printf("Money deposited successfully!\n");

}else{
    printf("Invalid Amount!\n");
}
fclose(fp);
break;

    case 3:
        fp=fopen("bank.txt","r+");
        fread(&a,sizeof(a),1,fp);

        float withdraw;
        printf("Enter amount to withdraw:");
        scanf("%f",&withdraw);
        if(withdraw>a.balance){
                printf("Insufficient balance!\n");
        }else if(withdraw>0){
            a.balance-=withdraw;
            rewind(fp);
            fwrite(&a,sizeof(a),1,fp);
            printf("Withdrawal successfully!\n");
        }else{
            printf("Invalid Amount!\n");
        }
        fclose(fp);
        break;

    case 4:
        fp=fopen("bank.txt","r");
        fread(&a,sizeof(a),1,fp);
        printf("\nAccount No:%d",a.accNo);
        printf("\nName:%s",a.name);
        printf("\nBalance:%.2f\n",a.balance);
        fclose(fp);
        break;

    case 5:
        printf("Thank You!\n");
        exit(0);

        default:
        printf("Invalid choice!\n");
    }
    }
    return 0;
}


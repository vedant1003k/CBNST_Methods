

const NFTs = []

function mintNFT (name,id,shirt_type) {
    const NFT ={
        "name":name,
        "id":id,
        "shirt_type":shirt_type,
    }
    NFTs.push(NFT)
    console.log("MintNFT "+ name)

}


// create a "loop" that will go through an "array" of NFT's
// and print their metadata with console.log()
function listNFTs () {
    for(let i=0;i<NFTs.length;i++)
    {
        console.log(NFTs[i]);
    }
}

// print the total number of NFTs we have minted to the console
function getTotalSupply() {
    console.log(NFTs.length);
}

// call your functions below this line

mintNFT("vedant","123","Hoodie")
listNFTs()
getTotalSupply()

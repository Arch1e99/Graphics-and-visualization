
/*
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
public class CTimer : MonoBehaviour
{
    public float mTime;
    public TMP_Text mTimer;
    [SerializeField] TextMeshProUGUI obj;
    public bool isGameOver;
    // Start is called before the first frame update
    void Start()
    {
        mTime = 0;
        isGameOver = false;
        mTimer = GetComponent<TextMeshProUGUI>();
    }
    // Update is called once per frame
    void Update()
    {
        if (isGameOver == false)
        {
            mTime += Time.deltaTime;
            float minutes = Mathf.FloorToInt(mTime / 60);
            float seconds = Mathf.FloorToInt(mTime % 60);
            mTimer.text = string.Format("{0:00}:{1:00}", minutes, seconds);
        }
    }
}
*/

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class CTimer : MonoBehaviour
{
    public float mTime;
    public TMP_Text mTimer;
    public bool isGameOver;

    public int totalTanks = 2;
    public int deliveredTanks = 0;

    void Start()
    {
        mTime = 0;
        isGameOver = false;
        mTimer = GetComponent<TextMeshProUGUI>();
    }

    void Update()
    {
        if (isGameOver == false)
        {
            mTime += Time.deltaTime;
            float minutes = Mathf.FloorToInt(mTime / 60);
            float seconds = Mathf.FloorToInt(mTime % 60);

            mTimer.text = string.Format("{0:00}:{1:00}   {2:00}/{3:00}", minutes, seconds, deliveredTanks, totalTanks);
        }
    }

    public void AddTank()
    {
        deliveredTanks++;

        if (deliveredTanks >= totalTanks)
        {
            isGameOver = true;

            float minutes = Mathf.FloorToInt(mTime / 60);
            float seconds = Mathf.FloorToInt(mTime % 60);
            mTimer.text = string.Format("Game Over\nCzas: {0:00}:{1:00}", minutes, seconds);
        }
    }
}
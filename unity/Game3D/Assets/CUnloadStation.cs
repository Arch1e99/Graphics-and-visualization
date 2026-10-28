/*
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CUnloadStation : MonoBehaviour
{
    // Start is called before the first frame update

    public CTimer mTimer;
    void Start()
    {
        mTimer = GameObject.Find("Timer").GetComponent<CTimer>();
    }

    // Update is called once per frame
    void Update()
    {
    }

    void OnTriggerExit(Collider obj)
    {
        if (obj.tag == "tagTank")
        {
            Destroy(obj.gameObject);

            mTimer.isGameOver = true;
        }
    }
}
*/

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CUnloadStation : MonoBehaviour
{
    public CTimer mTimer;

    void Start()
    {
        mTimer = GameObject.Find("Timer").GetComponent<CTimer>();
    }

    void Update()
    {
    }

    void OnTriggerExit(Collider obj)
    {
        if (obj.tag == "tagTank")
        {
            Destroy(obj.gameObject);

            if (mTimer != null)
            {
                mTimer.AddTank();
            }
        }
    }
}